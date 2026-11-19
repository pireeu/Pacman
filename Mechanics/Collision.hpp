#ifndef COLLISION_HPP
#define COLLISION_HPP

class Collision {
public:
    static bool checkWall(int nextY, int nextX, const char* map[], int mapHeight, int mapWidth);
    static bool checkGhostCollision(int pacY, int pacX, int ghostY, int ghostX);
};

#endif
