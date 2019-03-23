#include <Product/FarmProduct/ChickenEgg.h>

ChickenEgg::ChickenEgg():FarmProduct(ProductType::ChickenEggType,100){}

std::string ChickenEgg::render(){
    return "Chicken Egg";
}