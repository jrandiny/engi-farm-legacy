#include <Cell/Facility/Mixer.h>
#include <Cell/Cell.h>

Mixer::Mixer(int _x, int _y):Facility(_x,_y,CellType::MixerType){
    usable = true;
}

std::string Mixer::render(){
    return "M";
}
