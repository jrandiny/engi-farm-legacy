#include <Cell/Facility/Mixer.h>


Mixer::Mixer(int _x, int _y):Facility(_x,_y,Mxr){
    usable = true;
}

std::string Mixer::render(){
    return "M";
}
