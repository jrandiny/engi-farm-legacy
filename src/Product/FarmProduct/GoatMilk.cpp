#include <Product/FarmProduct/GoatMilk.h>

GoatMilk::GoatMilk():FarmProduct(GoatMk,100){}

std::string GoatMilk::render(){
    return "Goat Milk";
}