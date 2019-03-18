#include <Product/FarmProduct/DuckEgg.h>

DuckEgg::DuckEgg():FarmProduct(13){
    setHarga(100);
}

std::string DuckEgg::render(){
    return "Duck Egg";
}