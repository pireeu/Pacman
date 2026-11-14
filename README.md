# Pacman
karakter kuning yang harus makan semua titik di dalam labirin sambil kabur dari hantu yang ngejer. kita harus ngumpulin poin sebanyak-banyaknya dan jangan sampe ketangkep hantu.


Struktur File:

**Game/**
  * `Main.cpp` -> File utama untuk menjalankan game loop dan memanggil semua modul yang tersedia.
  * `Makefile` -> Berisi perintah untuk meng-compile seluruh modul program sekaligus.

**Object/**
  * `Pacman.hpp` -> Berisi struktur, posisi, dan mekanisme kontrol utama karakter Pac-Man.
  * `Ghost.hpp` -> Berisi fungsi, perilaku (AI), dan aturan pergerakan dari hantu-hantu musuh.
  * `Dot.hpp` -> Berisi fungsi dan titik-titik makanan yang tersebar di labirin.

**Mechanics/**
  * `Collision.hpp` -> Mekanisme deteksi tabrakan (antara Pac-Man dengan tembok labirin, titik makanan, dan hantu).
  * `Score.hpp` -> Mekanisme penghitungan skor, sisa nyawa (lives), dan status menang/kalah.

**Platform/**
  * `Map.hpp` -> Desain tata letak (layout) arena labirin permainan.
  * `Menu.hpp` -> Menampilkan menu utama, tampilan *Game Over*, dan layar kemenangan.
