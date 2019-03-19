#include <Product/FarmProduct/RabbitMeat.h>

RabbitMeat::RabbitMeat():FarmProduct(RabbitMt,100){}

std::string RabbitMeat::render(){
    return "Rabbit Meat";
}