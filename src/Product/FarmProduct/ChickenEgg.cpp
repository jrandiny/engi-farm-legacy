#include <Product/FarmProduct/ChickenEgg.h>

ChickenEgg::ChickenEgg():FarmProduct(10,100){}

std::string ChickenEgg::render(){
    return "Chicken Egg";
}