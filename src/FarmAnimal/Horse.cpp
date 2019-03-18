#include <FarmAnimal/Horse.h>
#include <iostream>
#include <memory>

Horse::Horse():FarmAnimal(5,2){
    posX=0;
    posY=0;
    eatStatus=false;
    deathStatus = false;
}

std::string Horse::speak(){
    return "Nay nay..!";
}

std::shared_ptr<Product> Horse::getProduct(){
    std::shared_ptr<Product> res = std::shared_ptr<Product>(new HorseMeat());
    return res;
}
std::string Horse::render(){
    return "H";
}