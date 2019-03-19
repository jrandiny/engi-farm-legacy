#include <Product/FarmProduct/DuckEgg.h>

DuckEgg::DuckEgg():FarmProduct(13,100){}

std::string DuckEgg::render(){
    return "Duck Egg";
}