#include <Product/FarmProduct/CowMilk.h>


CowMilk::CowMilk(){
    setHarga(100);
}

std::string CowMilk::render(){
    return "Cow Milk";
}