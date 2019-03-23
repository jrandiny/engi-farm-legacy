#include <Product/FarmProduct/CowMeat.h>

CowMeat::CowMeat():FarmProduct(ProductType::CowMeatType,100){}

std::string CowMeat::render(){
    return "Cow Meat";
}