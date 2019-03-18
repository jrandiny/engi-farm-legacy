#include <Map.h>

Map::Map(int x,int y){
    map = new std::vector<std::vector<std::shared_ptr<Cell>>(x)>(y);
}

//Cell& getSurrounding(int x, int y) const{
//    return cell;
//}
//
//Mixer& getMixer(int x, int y) const{
//    return mixer;
//}
//
//Truck& getTruck(int x, int y) const{
//    return truck;
//}
//
//Well& getWell(int x, int y) const{
//    return well;
//}
//
//FarmAnimal& getFarmAnimal(int x, int y) const{
//    return farm_animal;
//}