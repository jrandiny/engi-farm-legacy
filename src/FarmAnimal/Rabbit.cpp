#include <FarmAnimal/Rabbit.h>
#include <iostream>

Rabbit::Rabbit():FarmAnimal(5,2){
    posX=0;
    posY=0;
    eatStatus=false;
}

std::string Rabbit::speak(){
    return "Purr purr..!";
}

std::shared_ptr<Product> Rabbit::getProduct(){
    std::shared_ptr<Product> res = std::shared_ptr<Product>(new RabbitMeat());
    return res;
}

std::string Rabbit::render(){
    return "R";
}