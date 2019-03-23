#include <Product/FarmProduct/DuckEgg.h>

DuckEgg::DuckEgg():FarmProduct(ProductType::DuckEggType,100){}

std::string DuckEgg::render(){
    return "Duck Egg";
}