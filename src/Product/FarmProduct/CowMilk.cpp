#include <Product/FarmProduct/CowMilk.h>


CowMilk::CowMilk():FarmProduct(12){
    setHarga(100);
}

std::string CowMilk::render(){
    return "Cow Milk";
}