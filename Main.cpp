#include <iostream>
#include "Platform/Map.hpp"

int main() {
    std::cout << "=== GAME PAC-MAN C++ ===" << std::endl;
    std::cout << "Peta Labirin Utama:" << std::endl;
    std::cout << "------------------------" << std::endl;

    // Panggil objek Map
    Map gameMap;
    gameMap.drawMap();

    std::cout << "------------------------" << std::endl;
    std::cout << "Pondasi peta berhasil dimuat!" << std::endl;

    return 0;
}
