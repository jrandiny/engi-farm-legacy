/**
 * @file SimulationObject.h
 * @author Back End K3
 * @brief File berisi definisi class SimulationObject
 * @version 0.1
 * @date 2019-03-01
 */


#ifndef SIMULATIONOBJ_H
#define SIMULATIONOBJ_H

/**
 * @brief Kelas abstrak dasar SimulationObject
 * @class SimulationObject SimulationObject.h <SimulationObject.h>
 * 
 * Kelas ini adalah parent dari kelas Truck dan FarmAnimal\n
 * SimulationOject membuat object yang memiliki timer
 */
class SimulationObject{
    public:
        /**
         * @brief Konstruktor kelas SimulationObject
         * 
         */
        SimulationObject();

        /**
         * @brief Fungsi untuk update timer
         * 
         * Fungsi ini akan menjalankan semua timer untuk objek yang mengimplementasi SimulationObject\n
         * Fungsi ini harus dijalankan tiap kali tick di game
         */
        void tick();

        /**
         * @brief Aktivasi timer
         * 
         * Mengaktivasi timer pada SimulationObject, sebaiknya dipanggl sesudah setTimer
         */
        void activateTimer();

        /**
         * @brief Deaktivasi timer
         * 
         * Mengdeaktivasi timer pada SimulationObject
         */
        void deactivateTimer();


        /**
         * @brief Menetapkan waktu timer
         * 
         * @param timer Waktu timer
         */
        void setTimer(int timer);

        /**
         * @brief Menetapkan waktu dan aktivasi timer
         * 
         * @param timer Waktu timer
         */
        void setAndActivate(int timer);

    protected:
        /**
         * @brief Fungsi callback
         * 
         * Fungsi ini dipanggil saat timer mencapai 0
         */
        virtual void callback()=0;

    private:
        bool timerActive;
        int timer;
};


#endif