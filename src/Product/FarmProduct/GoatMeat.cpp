#include <Product/FarmProduct/GoatMeat.h>

GoatMeat::GoatMeat(){
    setHarga(100);
}

std::string GoatMeat::render(){
    return "Goat Meat";
}