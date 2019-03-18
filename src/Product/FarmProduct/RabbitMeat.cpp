#include <Product/FarmProduct/RabbitMeat.h>

RabbitMeat::RabbitMeat():FarmProduct(17){
    setHarga(100);
}

std::string RabbitMeat::render(){
    return "Rabbit Meat";
}