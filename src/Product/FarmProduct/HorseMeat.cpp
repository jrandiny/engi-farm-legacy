#include <Product/FarmProduct/HorseMeat.h>

HorseMeat::HorseMeat():FarmProduct(ProductType::HorseMeatType,100){}

std::string HorseMeat::render(){
    return "Horse Meat";
}