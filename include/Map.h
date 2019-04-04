/**
 * @file Map.h
 * @author Back End K3
 * @brief File berisi definisi class Map
 * @version 0.1
 * @date 2019-03-18
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <Cell/Cell.h>
#include <Cell/Facility.h>
#include <Cell/Facility/Mixer.h>
#include <Cell/Facility/Truck.h>
#include <Cell/Facility/Well.h>
#include <Cell/Land.h>
#include <FarmAnimal/FarmAnimal.h>
#include <memory>

/**
 * @brief Kelas riil turunan Renderable
 * @class Map Map.h <Map.h>
 * 
 * Kelas ini adalah kelas yang akan menyimpan peta permainan dan memanipulasinya * 
 */
class Map{
    public:
        /**
         * @brief Kelas pembanding shared_ptr dari Cell 
         */
        class cmpSharedPtrCell {
            public:
                /**
                 * @brief Fungsi pembanding tipe shared_ptr Cell didapat dari tipe
                 * 
                 * @param a Cell a
                 * @param b Cell b
                 * @return True jika shared_ptr Cell a lebih kecil dari shared_ptr Cell b
                 */
                bool operator()(const std::shared_ptr<Cell>& a, const std::shared_ptr<Cell>& b) const {
                    return (*a).getType() < (*b).getType();
                }
        };

        enum MoveType {Up=0,Right=1,Down=2,Left=3,Center=4};
        /**
         * @brief Konstruktor kelas Map dengan parameter
         * 
         * @param width Lebar peta
         * @param height Tinggi peta
         */
        Map(int width, int height);

        /**
         * @brief Mengatur peta
         * 
         * @param in Peta yang dimasukkan
         */
        void setMap(std::vector<std::vector<std::shared_ptr<Cell>>> in);

        /**
         * @brief Mengambil isi peta
         * 
         * @return peta 
         */
        std::vector<std::vector<std::shared_ptr<Cell>>> getMap() const;
        
        /**
         * @brief Mengembalikan objek di sekitar
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Referensi ke Cell
         */
        std::vector<std::shared_ptr<Cell>> getSurrounding(int x, int y);

        /**
         * @brief Mengembalikan objek Mixer
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Referensi ke Mixer
         */
        std::shared_ptr<Mixer> getMixer(int x, int y);

        /**
         * @brief Mengembalikan objek Truck
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Refrensi ke Truck
         */
        std::shared_ptr<Truck> getTruck(int x, int y);

        /**
         * @brief Mengembalikan objek Well
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Refrensi ke Well
         */
        std::shared_ptr<Well> getWell(int x, int y);

        /**
         * @brief Mengembalikan objek FarmAnimal
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Referensi ke FarmAnimal
         */
        std::shared_ptr<FarmAnimal> getFarmAnimal(int x, int y);

        /**
         * @brief Fungsi yang mengembalikan FarmAnimal di sekitar player
         * 
         * @param x Posisi X
         * @param y Posisi Y
         * @return std::vector<std::shared_ptr<FarmAnimal>> semua FarmAnimal di sekitar player
         */
        std::vector<std::shared_ptr<FarmAnimal>> getSurroundAnimal(int x, int y);

        /**
         * @brief Fungsi yang mengembalikan Cell yang berisi Facility di sekitas player
         * 
         * @param x Posisi X
         * @param y Posis Y
         * @return std::vector<std::shared_ptr<Cell>> semua cell yang berisi Facility di sekitar player
         */
        std::vector<std::shared_ptr<Facility>> getSurroundFacility(int x, int y, Cell::CellType type);
        
        /**
         * @brief Fungsi yang mengembalikan semua FarmAnimal di map
         * 
         * @return std::vector<std::shared_ptr<FarmAnimal>> semua FarmAnimal di map
         */
        std::vector<std::shared_ptr<FarmAnimal>> getAllFarmAnimal() const;


        void oneTick();
    private:
        std::vector<std::vector<std::shared_ptr<Cell>>> map;
        std::vector<std::shared_ptr<Land>> land;
        std::vector<std::shared_ptr<Mixer>> mixer;
        std::vector<std::shared_ptr<Truck>> truck;
        std::vector<std::shared_ptr<Well>> well;
        std::vector<std::shared_ptr<FarmAnimal>> farmAnimal;
        const int width;
        const int height;
        void setCellMap(int xFrom, int yFrom, int xTo, int yTo, Cell::CellType type);
        void setFacility(int jumlah, Cell::CellType type);
        void randomAnimalMap(int xFrom, int yFrom, int xTo, int yTo, Cell::CellType type, int jumlahHewan);

};


#endif