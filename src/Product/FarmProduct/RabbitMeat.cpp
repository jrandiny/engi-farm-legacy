#include <Product/FarmProduct/RabbitMeat.h>

RabbitMeat::RabbitMeat():FarmProduct(ProductType::RabbitMeatType,100){}

std::string RabbitMeat::render(){
    return "Rabbit Meat";
}