#include <Product/FarmProduct/HorseMeat.h>

HorseMeat::HorseMeat():FarmProduct(HorseMt,100){}

std::string HorseMeat::render(){
    return "Horse Meat";
}