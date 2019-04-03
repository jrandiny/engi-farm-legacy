#include <Player.h>
#include <Map.h>

const int initialWater = 10;
const int initialMoney = 100;
const int initialPosX = 0;
const int initialPosY = 0;

const int mapHeight = 10;
const int mapWidth = 10;

Map initializeMap(Map in){
    return in;
}

int main(){
    Player player(initialWater,initialMoney,initialPosX,initialPosY);
    Map map(mapWidth,mapHeight);

    

    return 0;
}