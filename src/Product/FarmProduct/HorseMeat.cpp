#include <Product/FarmProduct/HorseMeat.h>

HorseMeat::HorseMeat():FarmProduct(16){
    setHarga(100);
}

std::string HorseMeat::render(){
    return "Horse Meat";
}