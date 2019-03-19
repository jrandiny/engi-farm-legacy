#include <Product/FarmProduct/CowMilk.h>


CowMilk::CowMilk():FarmProduct(CowMk,100){}

std::string CowMilk::render(){
    return "Cow Milk";
}