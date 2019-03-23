#include <Product/FarmProduct/GoatMeat.h>

GoatMeat::GoatMeat():FarmProduct(ProductType::GoatMeatType,100){}

std::string GoatMeat::render(){
    return "Goat Meat";
}