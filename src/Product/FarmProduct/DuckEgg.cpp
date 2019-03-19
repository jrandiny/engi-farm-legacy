#include <Product/FarmProduct/DuckEgg.h>

DuckEgg::DuckEgg():FarmProduct(DkEgg,100){}

std::string DuckEgg::render(){
    return "Duck Egg";
}