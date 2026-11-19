#ifndef GHOST_HPP
#define GHOST_HPP

class Ghost {
public:
    int x, y;
    char symbol;

    Ghost(int startY, int startX, char sym);
    void moveRandom(const char* map[], int height, int width);
};

#endif
