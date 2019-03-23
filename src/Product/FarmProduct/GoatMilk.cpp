#include <Product/FarmProduct/GoatMilk.h>

GoatMilk::GoatMilk():FarmProduct(ProductType::GoatMilkType,100){}

std::string GoatMilk::render(){
    return "Goat Milk";
}