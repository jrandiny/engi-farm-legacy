#include <Product/FarmProduct/CowMeat.h>

CowMeat::CowMeat(){
    setHarga(100);
}

std::string CowMeat::render(){
    return "Cow Meat";
}