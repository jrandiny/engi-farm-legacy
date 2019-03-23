#include <Cell/Facility/Well.h>
#include <Cell/Cell.h>

Well::Well(int _x, int _y):Facility(_x,_y,CellType::WellType){
    usable = true;
}
std::string Well::render(){
    return "W";
}