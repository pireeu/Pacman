#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

class Map {
private:
    // Ukuran sederhana untuk peta labirin Pac-Man
    static const int HEIGHT = 5;
    static const int WIDTH = 11;

    // Array 2D untuk bentuk labirin (# = tembok, . = titik makanan, spasi = jalan)
    char grid[HEIGHT][WIDTH + 1] = {
        "###########",
        "#.#.....#.#",
        "#.###.#.###",
        "#.........#",
        "###########"
    };

public:
    // Fungsi untuk menampilkan peta ke layar
    void drawMap() {
        for (int i = 0; i < HEIGHT; i++) {
            std::cout << grid[i] << std::endl;
        }
    }
};

#endif
