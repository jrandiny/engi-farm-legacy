#include <Product/FarmProduct/CowMeat.h>

CowMeat::CowMeat():FarmProduct(11,100){}

std::string CowMeat::render(){
    return "Cow Meat";
}