#include <Product/FarmProduct/GoatMilk.h>

GoatMilk::GoatMilk(){
    setHarga(100);
}

std::string GoatMilk::render(){
    return "Goat Milk";
}