#include <Product/FarmProduct/CowMilk.h>


CowMilk::CowMilk():FarmProduct(ProductType::CowMilkType,100){}

std::string CowMilk::render(){
    return "Cow Milk";
}