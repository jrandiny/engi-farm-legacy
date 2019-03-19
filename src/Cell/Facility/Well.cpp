#include <Cell/Facility/Well.h>

Well::Well(int _x, int _y):Facility(_x,_y,Wll){
    usable = true;
}
std::string Well::render(){
    return "W";
}