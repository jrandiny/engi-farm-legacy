#include <FarmAnimal/Duck.h>
#include <iostream>

Duck::Duck():FarmAnimal(5,0){
    posX=0;
    posY=0;
    eatStatus=false;
    deathStatus = false;
}

std::string Duck::speak(){
    return "Quack quack..!";
}

std::shared_ptr<Product> Duck::getProduct(){
    std::shared_ptr<Product> res = std::shared_ptr<Product>(new DuckEgg());
    return res;
}

std::string Duck::render(){
    return "D";
}