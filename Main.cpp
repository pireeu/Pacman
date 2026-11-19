#include <ncurses.h>
#include <windows.h>
#include "Platform/Map.hpp"
#include "Platform/Menu.hpp"
#include "Object/Pacman.hpp"
#include "Object/Ghost.hpp"
#include "Mechanics/Collision.hpp"
#include "Mechanics/Score.hpp"

using namespace std;

// Implementasi sederhana fungsi Collision
bool Collision::checkWall(int nextY, int nextX, const char* map[], int mapHeight, int mapWidth) {
    if (nextY < 0 || nextY >= mapHeight || nextX < 0 || nextX >= mapWidth) return true;
    return map[nextY][nextX] == '#';
}

bool Collision::checkGhostCollision(int pacY, int pacX, int ghostY, int ghostX) {
    return (pacY == ghostY && pacX == ghostX);
}

// Implementasi Score
Score::Score() : currentScore(0), highScore(100) {}
void Score::add(int points) { currentScore += points; }
int Score::getScore() const { return currentScore; }

// Implementasi Pacman
Pacman::Pacman(int startY, int startX) : x(startX), y(startY), symbol('C'), lives(3) {}
void Pacman::move(int direction, const char* map[], int height, int width) {
    int nextY = y, nextX = x;
    if (direction == KEY_UP) nextY--;
    else if (direction == KEY_DOWN) nextY++;
    else if (direction == KEY_LEFT) nextX--;
    else if (direction == KEY_RIGHT) nextX++;

    if (!Collision::checkWall(nextY, nextX, map, height, width)) {
        y = nextY;
        x = nextX;
    }
}

// Implementasi Ghost
Ghost::Ghost(int startY, int startX, char sym) : x(startX), y(startY), symbol(sym) {}
void Ghost::moveRandom(const char* map[], int height, int width) {
    int choice = rand() % 4;
    int nextY = y, nextX = x;
    if (choice == 0) nextY--;
    else if (choice == 1) nextY++;
    else if (choice == 2) nextX--;
    else if (choice == 3) nextX++;

    if (!Collision::checkWall(nextY, nextX, map, height, width)) {
        y = nextY;
        x = nextX;
    }
}

// Implementasi Menu & Map
void Menu::showMainTitle() const {
    initscr();
    printw("=== GAME PACMAN TERMINAL ===\nTekan tombol apa saja untuk mulai...");
    refresh();
    getch();
}

void Map::draw() const {
    for (int i = 0; i < HEIGHT; i++) {
        mvprintw(i, 0, "%s", grid[i]);
    }
}

int main() {
    Menu menu;
    menu.showMainTitle();

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(0));

    Map gameMap;
    Pacman pacman(5, 5);
    Ghost ghost(7, 14, 'G');
    Score score;

    int ch;
    bool running = true;

    while (running) {
        clear();
        gameMap.draw();
        mvprintw(pacman.y, pacman.x, "%c", pacman.symbol);
        mvprintw(ghost.y, ghost.x, "%c", ghost.symbol);
        
        mvprintw(16, 2, "SCORE: %d | LIVES: %d", score.getScore(), pacman.lives);
        refresh();

        ch = getch();
        if (ch == 'q' || ch == 'Q') {
            running = false;
        } else {
            pacman.move(ch, gameMap.grid, Map::HEIGHT, Map::WIDTH);
            ghost.moveRandom(gameMap.grid, Map::HEIGHT, Map::WIDTH);
        }

        if (Collision::checkGhostCollision(pacman.y, pacman.x, ghost.y, ghost.x)) {
            pacman.lives--;
            if (pacman.lives <= 0) {
                clear();
                mvprintw(8, 5, "GAME OVER! Tekan tombol apapun untuk keluar.");
                refresh();
                getch();
                break;
            } else {
                pacman.y = 5;
                pacman.x = 5;
            }
        }

        Sleep(150);
    }

    endwin();
    return 0;
}
