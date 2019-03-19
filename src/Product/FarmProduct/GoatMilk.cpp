#include <Product/FarmProduct/GoatMilk.h>

GoatMilk::GoatMilk():FarmProduct(15,100){}

std::string GoatMilk::render(){
    return "Goat Milk";
}