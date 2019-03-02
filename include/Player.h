/**
 * @file Player.h
 * @author Back End K3
 * @brief File berisi definisi kelas Player
 * @version 0.1
 * @date 2019-03-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <LinkedList.h>
#include <Product/Product.h>
#include <Product/SideProduct.h>
#include <FarmAnimal/FarmAnimal.h>
#include <Cell/Facility/Well.h>
#include <Cell/Facility/Truck.h>
#include <Cell/Land.h>
/**
 * @brief Kelas riil Player
 * @class Player Player.h <Player.h>
 * 
 * Player adalah objek yang digunakan pemain sebagai karakter utama
 */
class Player{
    private:
        const int MAX_WATER = 50;// maximum jumlah air yang bisa ditampung
        const int MAX_ITEM_BAG = 10; // maximum product yang bisa ditampung di tas
        LinkedList<Product> bag; // tas dari player
        // const LinkedList<SideProduct> recipe; // daftar resep side product
        int water; // jumlah air saat ini
        int money; // jumlah uang saat ini
        int posX; // posisi X player
        int posY; // posisi X player
    public:
        /**
         * @brief Konstruktor Player tanpa parameter
         * 
         */
        Player();
        /**
         * @brief Konstruktor Player dengan parameter
         * 
         * @param water jumlah air
         * @param money jumlah uang
         * @param posX Lokasi X
         * @param posY Lokasi Y
         */
        Player(int water, int money, int posX, int posY);
        /**
         * @brief Destruktor Player
         * 
         */
        ~Player();

        /**
         * @brief getter untuk data bag
         * 
         * @return list produk isi dari tas
         */
        LinkedList<Product> getBag();
        /**
         * @brief getter untuk data water
         * 
         * @return jumlah air
         */
        int getWater();
        /**
         * @brief getter untuk data uang
         * 
         * @return jumlah uang
         */
        int getMoney();
        /**
         * @brief getter untuk data posX
         * 
         * @return lokasi X player
         */
        int getPosX();
        /**
         * @brief getter untuk data posY
         * 
         * @return lokasi Y player
         */
        int getPosY();

        /**
         * @brief memindahkan posisi player
         * 
         * mengubah posX dan posY tergantung input arah
         * 
         * @param arah (0: atas, 1: kanan, 2: bawah, 3: kiri)
         */
        void move(int arah);
        // berbicara dengan hewan memanggil speak pada FarmAnimal
        /**
         * @brief berbicara dengan hewan
         * 
         * berbicara dengan hewan memanggil speak pada FarmAnimal
         * 
         * @param hewan hewan yang diajak berbicara
         */
        void talk(FarmAnimal& hewan);
        // berinteraksi dengan FarmAnimal atau Facility
        /**
         * @brief berinteraksi dengan FarmAnimal
         * 
         * interaksi dengan hewan di coop menghasilkan egg
         * interaksi dengan hewan di grassland menghasilkan milk
         * 
         * @param hewan hewan yang diinteraksikan
         */
        void interact(FarmAnimal& hewan);
        /**
         * @brief berinteraksi dengan Fasilitas (Well)
         * 
         * interaksi dengan well mengisi water hingga penuh
         * 
         * @param w objek well yang diambil sumurnya
         */
        void interact(Well w);
        /**
         * @brief berinteraksi dengan Fasilitas (Truck)
         * 
         * interaksi dengan truck mengosongkan bag dan mendapat money
         * dan menjadikan truck tidak bisa digunakan untu beberapa saat
         * 
         * @param t truck yang akan digunakan untuk menjual produk
         */
        void interact(Truck t);
        /**
         * @brief membunuh hewan untuk diambil dagingnya
         * 
         * dilakukan untuk mengambil meat dari MeatProducingFarmAnimal
         * hewan langsung dianggap mati
         * 
         * @param hewan hewan yang akan disembelih
         */
        void kill(FarmAnimal& hewan);
        /**
         * @brief untuk menyiram land tempat player berdiri
         * 
         * @param l land yang akan disiram
         */
        void grow(Land l);
        /**
         * @brief membuat SideProduct
         * 
         * digunakan pada mixer dan menghasilkan SideProduct
         * 
         * @param sp SideProduct yang ingin dibuat
         */
        void mix(SideProduct& sp);
};

#endif