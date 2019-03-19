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

class Map{
    public:
        class cmpSharedPtrLoc {
            public:
                bool operator()(const std::shared_ptr<Product>& a, const std::shared_ptr<Product>& b) const {
                    return (*a).getId() < (*b).getId();
                }
        };
        /**
         * @brief Konstruktor kelas Map dengan parameter
         * 
         * @param width Lebar peta
         * @param height Tinggi peta
         */
        Map(int width, int height);
        
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

    private:
        std::vector<std::vector<std::shared_ptr<Cell>>> map;
        std::vector<std::shared_ptr<Land>> land;
        std::vector<std::shared_ptr<Mixer>> mixer;
        std::vector<std::shared_ptr<Truck>> truck;
        std::vector<std::shared_ptr<Well>> well;
        std::vector<std::shared_ptr<FarmAnimal>> farmAnimal;
        const int width;
        const int height;
};


#endif