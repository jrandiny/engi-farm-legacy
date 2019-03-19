#include <Product/FarmProduct/GoatMeat.h>

GoatMeat::GoatMeat():FarmProduct(GoatMt,100){}

std::string GoatMeat::render(){
    return "Goat Meat";
}