#include <Product/FarmProduct/CowMeat.h>

CowMeat::CowMeat():FarmProduct(CowMt,100){}

std::string CowMeat::render(){
    return "Cow Meat";
}