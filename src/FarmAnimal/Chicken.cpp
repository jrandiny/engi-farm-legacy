#include <FarmAnimal/Chicken.h>
#include <iostream>

Chicken::Chicken():FarmAnimal(5,0){
    posX=0;
    posY=0;
    eatStatus=false;
}

std::string Chicken::speak(){
    return "Cook-a-Doodle-Doo!";
}

std::shared_ptr<Product> Chicken::getProduct(){
    std::shared_ptr<Product> res = std::shared_ptr<Product>(new ChickenEgg());
    return res;
}

std::string Chicken::render(){
    return "C";
}