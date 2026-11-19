#ifndef PACMAN_HPP
#define PACMAN_HPP

class Pacman {
public:
    int x, y;
    char symbol;
    int lives;

    Pacman(int startY, int startX);
    void move(int direction, const char* map[], int height, int width);
};

#endif
