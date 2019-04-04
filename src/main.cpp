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

const int initialWater = 5;
const int initialMoney = 0;
const int initialPosX = 0;
const int initialPosY = 0;

const int mapHeight = 10;
const int mapWidth = 10;

int main(){
    Player player(initialWater,initialMoney,initialPosX,initialPosY);
    Map map(mapWidth,mapHeight);
    UI ui;
    bool action;
    std::vector<std::string> input;
    std::string command;
    std::vector<std::string> param;
    std::string output;
    std::vector<std::shared_ptr<Cell>> playerSurr;
    std::vector<std::shared_ptr<FarmAnimal>> surroundingAnimal;
    std::vector<std::shared_ptr<Facility>> surroundingFacility;
    player.addBag(std::shared_ptr<Product>(new CowMilk()));
    player.addBag(std::shared_ptr<Product>(new CowMilk()));
    player.addBag(std::shared_ptr<Product>(new ChickenEgg()));
    player.addBag(std::shared_ptr<Product>(new DuckEgg()));
    player.addBag(std::shared_ptr<Product>(new CowMilk()));

    while (1){
        action = false;
        output = "";
        ui.drawMap(map, player);
        ui.drawPlayerStat(player);
        input = ui.getInput();
        if(input.size()==1 || (input.size()==2 && input[0]=="MIX")){
            command = input[0];
            std::copy(input.begin()+1,input.end(),std::back_inserter(param));
        }

        playerSurr = map.getSurrounding(player.getPosX(),player.getPosY());
        if(command=="INTERACT"){
            surroundingAnimal = map.getSurroundAnimal(player.getPosX(),player.getPosY());
            if(surroundingAnimal.size()>0){
                try{
                    player.interact(*(surroundingAnimal[0]));
                    action = true;
                } catch(const std::runtime_error e){
                    output = e.what();
                }
            }else{
                surroundingFacility = map.getSurroundFacility(player.getPosX(),player.getPosY(),Cell::WellType);
                if(surroundingFacility.size()>0){
                    player.interact(*(std::static_pointer_cast<Well>(surroundingFacility[0])));
                    action = true;
                } else {
                    surroundingFacility = map.getSurroundFacility(player.getPosX(),player.getPosY(),Cell::TruckType);
                    if(surroundingFacility.size()>0){
                        try{
                            player.interact(*(std::static_pointer_cast<Truck>(surroundingFacility[0])));
                            action = true;
                        } catch (const std::runtime_error e){
                            output = e.what();
                        }
                    } else {
                        output = "Can't interact";
                    }
                }
            }
        }else if(command=="TALK"){ //command = talk
            surroundingAnimal = map.getSurroundAnimal(player.getPosX(),player.getPosY());

            if(surroundingAnimal.size()>0){
                output = player.talk(*(surroundingAnimal[0]));
                action = true;
            }else{
                output = "No animal found";
            }
        }else if(command=="KILL"){ //command = kill
            surroundingAnimal = map.getSurroundAnimal(player.getPosX(),player.getPosY());
            if(surroundingAnimal.size()>0){
                try{
                    player.kill(*(surroundingAnimal[0]));
                    action = true;
                } catch(const std::runtime_error e){
                    output = e.what();
                }
            }else{
                output = "No animal found";
            }
        }else if(command=="GROW"){ //command = grow
            std::shared_ptr<Land> land = std::static_pointer_cast<Land>(map.getMap()[player.getPosY()][player.getPosX()]); // land sekarang
            try{
                player.grow(*(land));
                action = true;
            }catch (const std::runtime_error e){
                output=e.what();
            }
        }else if(command=="MIX"){ //command = mix
            surroundingFacility = map.getSurroundFacility(player.getPosX(),player.getPosY(),Cell::MixerType);
            if(surroundingFacility.size()>0 && param.size()>0){
                if(param[0]=="BEEFROLADE"){
                    try{
                        player.mix(Product::BeefRoladeType);
                        action = true;
                    } catch (const std::runtime_error e){
                        output = e.what();
                    }
                } else if(param[0] == "EGGBENEDICT"){
                    try{
                        player.mix(Product::EggBenedictType);
                        action = true;
                    } catch (const std::runtime_error e){
                        output = e.what();
                    }
                }else if(param[0] == "MEATZA"){
                    try{
                        player.mix(Product::MeatzaType);
                        action = true;
                    } catch (const std::runtime_error e){
                        output = e.what();
                    }
                }else{
                    output = "Invalid recipe";
                }
            }else{
                output = "Invalid input";
            }
        }else if(command=="UP"){
            try{
                player.move(Map::Up, playerSurr);
                action = true;
            }catch (const std::runtime_error e){
                output = e.what();
            }
        }else if(command=="DOWN"){
            try{
                player.move(Map::Down, playerSurr);
                action = true;
            }catch (const std::runtime_error e){
                output = e.what();
            }
        }else if(command=="LEFT"){
            try{
                player.move(Map::Left, playerSurr);
                action = true;
            }catch (const std::runtime_error e){
                output = e.what();
            }
        }else if(command=="RIGHT"){
            try{
                player.move(Map::Right, playerSurr);
                action = true;
            }catch (const std::runtime_error e){
                output = e.what();
            }
        }else {
            output = "Wrong command";
        }
        if(action){
            map.moveAllAnimal();
        }

        ui.drawTooltip(output);
        
    }
    return 0;
}
