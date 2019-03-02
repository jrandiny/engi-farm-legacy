#include <Product/FarmProduct/ChickenEgg.h>

ChickenEgg::ChickenEgg(){
    setHarga(100);
}

std::string ChickenEgg::render(){
    return "Chicken Egg";
}