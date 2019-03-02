#include <Cell/Facility/Well.h>

Well::Well(int _x, int _y):Facility(_x,_y){
    usable = true;
}
std::string Well::render(){
    return "W";
}