#include <Player.h>
#include <Map.h>
#include <ncurses.h>
#include <locale.h>
#include <algorithm>
#include <utility>
#include <UI.h>

const int initialWater = 50;
const int initialMoney = 0;

const int mapHeight = 8;
const int mapWidth = 8;

int main(){
    Map map(mapWidth,mapHeight);

    int initialPosX;
    int initialPosY;
    do{
        initialPosX = rand()%mapWidth;
        initialPosY = rand()%mapHeight;
        // find the position that is not occupied
    } while (map.getMap()[initialPosY][initialPosX]->isOccupied());
    // initialize player
    Player player(initialWater,initialMoney,initialPosX,initialPosY);
    // occupy posisi player sekarang
    std::static_pointer_cast<Land>(map.getMap()[initialPosY][initialPosX])->occupy();
    // kamus
    UI ui;
    bool action;
    bool quit;
    std::vector<std::string> input;
    std::string command;
    std::vector<std::string> param;
    std::string output;
    std::vector<std::shared_ptr<Cell>> playerSurr;
    std::vector<std::shared_ptr<FarmAnimal>> surroundingAnimal;
    std::vector<std::shared_ptr<Facility>> surroundingFacility;

    quit = false;
    // check number of animal
    std::vector<std::shared_ptr<FarmAnimal>> animalNow = map.getAllFarmAnimal();
    while (!quit && animalNow.size()>0){ // looping main
        action = false;
        output = "";
        ui.drawMap(map, player);
        ui.drawPlayerStat(player);
        input = ui.getInput();
        // input validation
        if((input.size()==1 && input[0]!="MIX") || (input.size()==2 && input[0]=="MIX")){
            command = input[0]; // get the command
            param.clear();  // initialize param
            //copy from input to param
            std::copy(input.begin()+1,input.end(),std::back_inserter(param));
        } else {
            // if input is wrong
            command = ""; 
        }
        // get the cells at player surrounding
        playerSurr = map.getSurrounding(player.getPosX(),player.getPosY());
        // find the animal in surrounding
        surroundingAnimal = map.getSurroundAnimal(player.getPosX(),player.getPosY());
        if(command=="INTERACT"){ // command = interact
            if(surroundingAnimal.size()>0){
                // there is animal found
                try{
                    player.interact(*(surroundingAnimal[0]));
                    action = true;
                } catch(const std::runtime_error e){
                    output = e.what();
                }
            }else{
                // no animal found, try find well
                surroundingFacility = map.getSurroundFacility(player.getPosX(),player.getPosY(),Cell::WellType);
                if(surroundingFacility.size()>0){
                    // there is well found
                    try{
                        player.interact(*(std::static_pointer_cast<Well>(surroundingFacility[0])));
                        action = true;
                    } catch (const std::runtime_error e){
                        output = e.what();
                    }
                } else {
                    // no well found, try find truck
                    surroundingFacility = map.getSurroundFacility(player.getPosX(),player.getPosY(),Cell::TruckType);
                    if(surroundingFacility.size()>0){
                        // there is truck found
                        try{
                            player.interact(*(std::static_pointer_cast<Truck>(surroundingFacility[0])));
                            action = true;
                        } catch (const std::runtime_error e){
                            output = e.what();
                        }
                    } else {
                        // nothing in player surrounding
                        output = "Can't interact";
                    }
                }
            }
        }else if(command=="TALK"){ //command = talk
            if(surroundingAnimal.size()>0){
                // there is animal found
                output = player.talk(*(surroundingAnimal[0]));
                action = true;
            }else{
                output = "No animal found";
            }
        }else if(command=="KILL"){ //command = kill
            if(surroundingAnimal.size()>0){
                // there is animal found
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
            // get Land on player current position
            std::shared_ptr<Land> land = std::static_pointer_cast<Land>(map.getMap()[player.getPosY()][player.getPosX()]);
            try{
                player.grow(*(land));
                action = true;
            }catch (const std::runtime_error e){
                output=e.what();
            }
        }else if(command=="MIX"){ //command = mix
            // find the mixer nearby
            surroundingFacility = map.getSurroundFacility(player.getPosX(),player.getPosY(),Cell::MixerType);
            if(surroundingFacility.size()>0){
                // there is mixer found
                if(param[0]=="BEEFROLADE"){
                    // side product is beef rolade
                    try{
                        player.mix(Product::BeefRoladeType);
                        action = true;
                    } catch (const std::runtime_error e){
                        output = e.what();
                    }
                } else if(param[0] == "EGGBENEDICT"){
                    // side product is egg benedict
                    try{
                        player.mix(Product::EggBenedictType);
                        action = true;
                    } catch (const std::runtime_error e){
                        output = e.what();
                    }
                }else if(param[0] == "MEATZA"){
                    // side product is meatza
                    try{
                        player.mix(Product::MeatzaType);
                        action = true;
                    } catch (const std::runtime_error e){
                        output = e.what();
                    }
                }else{
                    // no side product found
                    output = "Invalid recipe";
                }
            }else{
                // no mixer nearby
                output = "No mixer found";
            }
        }else if(command=="UP"){ // command = up
            try{
                player.move(Map::Up, playerSurr);
                action = true;
            }catch (const std::runtime_error e){
                output = e.what();
            }
        }else if(command=="DOWN"){ // command = down
            try{
                player.move(Map::Down, playerSurr);
                action = true;
            }catch (const std::runtime_error e){
                output = e.what();
            }
        }else if(command=="LEFT"){ // command = left
            try{
                player.move(Map::Left, playerSurr);
                action = true;
            }catch (const std::runtime_error e){
                output = e.what();
            }
        }else if(command=="RIGHT"){ // command = right
            try{
                player.move(Map::Right, playerSurr);
                action = true;
            }catch (const std::runtime_error e){
                output = e.what();
            }
        }else if(command=="QUIT"){ // command = quit
            quit=true;
        }else {
            // can't recognize command
            if(command!="RESIZE")
                output = "Wrong command";
        }

        if(action){
            // if there is action happend
            map.oneTick();
        }
        ui.drawTooltip(output);
        animalNow = map.getAllFarmAnimal();
    }
    if(!quit){
        // if all animal is dead
        ui.drawTooltip("GAME OVER");
        input = ui.getInput();
    }
    return 0;
}
