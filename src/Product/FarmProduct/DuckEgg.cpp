#include <Product/FarmProduct/DuckEgg.h>

DuckEgg::DuckEgg(){
    setHarga(100);
}

std::string DuckEgg::render(){
    return "Duck Egg";
}