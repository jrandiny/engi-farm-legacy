/**
 * @file Player.h
 * @author Back End K3
 * @brief File berisi definisi class Player
 * @version 0.1
 * @date 2019-03-01
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
#include <memory>
#include <map>

/**
 * @brief Kelas riil turunan Renderable
 * @class Player Player.h <Player.h>
 * 
 * Player adalah objek yang digunakan pemain sebagai karakter utama
 */
class Player: public Renderable{
    public:
        /**
         * @brief Kelas pembanding shared_ptr dari Product
         */
        class cmpSharedPtrProduct {
            public:
                /**
                 * @brief Fungsi pembanding tipe shared_ptr produk didapat dari id
                 * 
                 * @param a Produk a
                 * @param b Produk b
                 * @return True jika shared_ptr Produk a lebih kecil dari shared_ptr Produk b 
                 */
                bool operator()(const std::shared_ptr<Product>& a, const std::shared_ptr<Product>& b) const {
                    return (*a).getId() < (*b).getId();
                }
        };

        /**
         * @brief Konstruktor kelas Player
         * 
         */
        Player();
        /**
         * @brief Konstruktor kelas Player dengan parameter
         * 
         * @param water jumlah air
         * @param money jumlah uang
         * @param posX Lokasi X
         * @param posY Lokasi Y
         */
        Player(int water, int money, int posX, int posY);
        /**
         * @brief Mengembalikan bag
         * 
         * @return std::mao of shared_ptr of Product isi dari tas
         */
        std::map<std::shared_ptr<Product>,int,cmpSharedPtrProduct> getBag();

        /**
         * @brief Menambah Product kedalam bag
         * 
         */
        void addBag(std::shared_ptr<Product> p);
        /**
         * @brief Mengembalikan jumlah water
         * 
         * @return jumlah air
         */
        int getWater();
        /**
         * @brief Mengembalikan jumlah money
         * 
         * @return jumlah uang
         */
        int getMoney();
        /**
         * @brief Mengembalikan posX
         * 
         * @return lokasi X Player
         */
        int getPosX();
        /**
         * @brief Mengembalikan posY
         * 
         * @return lokasi Y Player
         */
        int getPosY();

        /**
         * @brief Memindahkan posisi Player
         * 
         * mengubah posX dan posY tergantung input arah
         * 
         * @param arah (0: atas, 1: kanan, 2: bawah, 3: kiri)
         */
        void move(int arah);
        /**
         * @brief Berbicara dengan hewan
         * 
         * berbicara dengan hewan memanggil speak pada FarmAnimal
         * 
         * @param hewan hewan yang diajak berbicara
         */
        std::string talk(FarmAnimal& hewan);
        /**
         * @brief Berinteraksi dengan FarmAnimal
         * 
         * interaksi dengan hewan di Coop menghasilkan egg
         * interaksi dengan hewan di GrassLand menghasilkan milk
         * 
         * @param hewan hewan yang diinteraksikan
         */
        void interact(FarmAnimal& hewan);
        /**
         * @brief Berinteraksi dengan Fasilitas (Well)
         * 
         * interaksi dengan Well mengisi water hingga penuh
         * 
         * @param w objek Well yang diambil sumurnya
         */
        void interact(Well&);
        /**
         * @brief Berinteraksi dengan Fasilitas (Truck)
         * 
         * interaksi dengan Truck mengosongkan bag dan mendapat money
         * dan menjadikan Truck tidak bisa digunakan untuk beberapa saat
         * 
         * @param t Truck yang akan digunakan untuk menjual Product
         */
        void interact(Truck& truck);
        /**
         * @brief Membunuh hewan untuk diambil dagingnya
         * 
         * dilakukan untuk mengambil meat dari MeatProducingFarmAnimal
         * hewan langsung dianggap mati
         * 
         * @param hewan hewan yang akan disembelih
         */
        void kill(FarmAnimal& hewan);
        /**
         * @brief Menyiram Land tempat Player berdiri
         * 
         * @param l Land yang akan disiram
         */
        void grow(Land& l);
        /**
         * @brief Membuat SideProduct
         * 
         * digunakan pada Mixer dan menghasilkan SideProduct
         * 
         * @param nama nama SideProduct yang ingin dibuat
         */
        void mix(std::string nama);
        /**
         * @brief Mengembalikan lambang Player
         * 
         * @return char lambang yang ditampilkan untuk Player
         */
        std::string render();

    private:
        class Resep{
            public:
                static std::shared_ptr<SideProduct> getRecipe(std::string name);
        };

        const int MAX_WATER = 50;// maximum jumlah air yang bisa ditampung
        const int MAX_ITEM_BAG = 10; // maximum Product yang bisa ditampung di tas
        int itemNow;
        std::map<std::shared_ptr<Product>,int,cmpSharedPtrProduct> bag; // tas dari player
        int water; // jumlah air saat ini
        int money; // jumlah uang saat ini
        int posX; // posisi X player
        int posY; // posisi X player
};

#endif