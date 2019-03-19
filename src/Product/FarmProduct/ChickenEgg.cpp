#include <Product/FarmProduct/ChickenEgg.h>

ChickenEgg::ChickenEgg():FarmProduct(ChickEgg,100){}

std::string ChickenEgg::render(){
    return "Chicken Egg";
}