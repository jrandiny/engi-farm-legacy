/**
 * @file UI.h
 * @author Back End K3
 * @brief File berisi definisi class UI
 * @version 0.1
 * @date 2019-04-01
 */

#ifndef UI_H
#define UI_H

#include <string>
#include <Map.h>
#include <map>
#include <Player.h>
#include <ncurses.h>

/**
 * @brief Kelas abstrak dasar UI
 * @class UI UI.h <UI.h>
 * 
 * UI adalah kelas untuk membuat gambar tampilan ke layar
 */
class UI{
    public:
        /**
         * @brief Konstruktor kelas UI
         *
         */
        UI();

        /**
         * @brief Destruktor kelas UI
         * 
         */
        ~UI();
        
        /**
         * @brief Fungsi mengembalikan string input user
         * 
         * @return string yang diinput user
         */
        std::string getInput();

        /**
         * @brief Menggambarkan peta dari map yang diinput
         *  
         * @param in peta
         */
        void drawMap(Map in, Player P);

        /**
         * @brief Menggambarkan statistik player
         * 
         * @param p player
         */
        void drawPlayerStat(Player p);

        void drawTooltip(std::string input);

    private:
        const int bottomBarHeight = 3;
        const int titleBarHeight = 4;
        
        WINDOW *mapPanel;
        WINDOW *titlePanel;
        WINDOW *commandPanel;
        WINDOW *inventoryPanel;
        WINDOW *moneyPanel;
        WINDOW *waterPanel;

        void drawBorders(WINDOW *screen);
};
#endif