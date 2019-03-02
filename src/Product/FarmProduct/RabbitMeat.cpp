#include <Product/FarmProduct/RabbitMeat.h>

RabbitMeat::RabbitMeat(){
    setHarga(100);
}

std::string RabbitMeat::render(){
    return "Rabbit Meat";
}