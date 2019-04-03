#include <Player.h>
#include <Map.h>
#include <ncurses.h>
#include <locale.h>
#include <algorithm>
#include <utility>
#include <UI.h>

#include <Product/FarmProduct/CowMilk.h>
#include <Product/FarmProduct/ChickenEgg.h>
#include <Product/FarmProduct/DuckEgg.h>

#include <time.h>

const int initialWater = 10;
const int initialMoney = 100;
const int initialPosX = 0;
const int initialPosY = 0;

const int mapHeight = 10;
const int mapWidth = 10;

// std::pair<int,int> changePos(std::pair<int,int> pair, int move){
//     std::pair<int,int> temp = pair;
//     switch(move){
//         case Map::Up:
//             temp.second--;
//             break;
//         case Map::Right:
//             temp.first++;
//             break;
//         case Map::Down:
//             temp.second++;
//             break;
//         case Map::Left:
//             temp.first--;
//             break;
//     }
//     return temp;
// }


// std::pair<int ,int> findFacility(int x, int y,Cell::CellType type, std::vector<std::shared_ptr<Cell>> surr){
//     bool found=false;
//     int i=0;
//     std::pair<int,int> result = std::pair<int,int>(x,y);
//     while(!found && i<4){
//         if(surr[i]!=nullptr){
//             if(surr[i]->getType()==type){
//                 found=true;
//             }else{
//                 i++;
//             }
//         }else{
//             i++;
//         }
//     }
    
//     if(found){
//         result=changePos(result,i);       
//     }else{
//         result.first=-1;
//         result.second=-1;
//     }
//     return result;
// }


int main(){
    Player player(initialWater,initialMoney,initialPosX,initialPosY);
    Map map(mapWidth,mapHeight);
    UI ui;
    std::pair<int,int> posisi;

    player.addBag(std::shared_ptr<Product>(new CowMilk()));
    player.addBag(std::shared_ptr<Product>(new CowMilk()));
    player.addBag(std::shared_ptr<Product>(new ChickenEgg()));
    player.addBag(std::shared_ptr<Product>(new DuckEgg()));
    player.addBag(std::shared_ptr<Product>(new CowMilk()));

    
    std::string input;
    std::string output;
    std::vector<std::shared_ptr<Cell>> playerSurr;

    while (1){
        ui.drawMap(map, player);
        ui.drawPlayerStat(player);
        input = ui.getInput();

        playerSurr = map.getSurrounding(player.getPosX(),player.getPosY());

        output = "";

        if(input=="INTERACT"){
            std::vector<std::shared_ptr<FarmAnimal>> surroundingAnimal = map.getSurroundAnimal(player.getPosX(),player.getPosY());
            
            if(surroundingAnimal.size()>0){
                try{
                    player.interact(*(surroundingAnimal[0]));
                } catch(const std::runtime_error e){
                    output = e.what();
                }
            }else{
                output = "No animal found";
            }
            
        }else if(input=="TALK"){ //command = talk
            std::vector<std::shared_ptr<FarmAnimal>> surroundingAnimal = map.getSurroundAnimal(player.getPosX(),player.getPosY());

            if(surroundingAnimal.size()>0){
                output = player.talk(*(surroundingAnimal[0]));
            }else{
                output = "No animal found";
            }

        }else if(input=="KILL"){ //command = kill
            std::vector<std::shared_ptr<FarmAnimal>> surroundingAnimal = map.getSurroundAnimal(player.getPosX(),player.getPosY());
            if(surroundingAnimal.size()>0){
                try{
                    player.kill(*(surroundingAnimal[0]));
                } catch(const std::runtime_error e){
                    output = e.what();
                }
            }else{
                output = "No animal found";
            }
          
        }else if(input=="GROW"){ //command = grow
            std::shared_ptr<Land> land = std::static_pointer_cast<Land>(map.getMap()[player.getPosY()][player.getPosX()]); // land sekarang
            player.grow(*(land));
        }else if(input=="MIX"){ //command = mix
            // posisi = findFacility(player.getPosX(),player.getPosY(),Cell::MixerType,playerSurr);
            // if(posisi.first != -1 && posisi.second != -1){
            //     // player.mix(*(map.getMixer(posisi.first,posisi.second)));
            // }
        }else if(input=="UP"){
            player.move(Map::Up, playerSurr);
        }else if(input=="DOWN"){
            player.move(Map::Down, playerSurr);
        }else if(input=="LEFT"){
            player.move(Map::Left, playerSurr);
        }else if(input=="RIGHT"){
            player.move(Map::Right, playerSurr);
        }else {
            output = "Wrong command";
        }

        ui.drawTooltip(output);
        map.moveAllAnimal();
    }
    return 0;
}
