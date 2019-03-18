#include <Product/FarmProduct/GoatMilk.h>

GoatMilk::GoatMilk():FarmProduct(15){
    setHarga(100);
}

std::string GoatMilk::render(){
    return "Goat Milk";
}