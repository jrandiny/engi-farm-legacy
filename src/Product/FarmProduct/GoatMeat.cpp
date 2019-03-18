#include <Product/FarmProduct/GoatMeat.h>

GoatMeat::GoatMeat():FarmProduct(14){
    setHarga(100);
}

std::string GoatMeat::render(){
    return "Goat Meat";
}