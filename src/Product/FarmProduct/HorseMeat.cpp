#include <Product/FarmProduct/HorseMeat.h>

HorseMeat::HorseMeat(){
    setHarga(100);
}

std::string HorseMeat::render(){
    return "Horse Meat";
}