#include <Product/FarmProduct/CowMilk.h>


CowMilk::CowMilk():FarmProduct(12,100){}

std::string CowMilk::render(){
    return "Cow Milk";
}