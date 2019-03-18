#include <FarmAnimal/Cow.h>
#include <iostream>

Cow::Cow(int type):FarmAnimal(5,type){
    posX=0;
    posY=0;
    eatStatus=false;
    deathStatus = false;
}

std::string Cow::speak(){
    return "Moooooooo..!";
}

std::shared_ptr<Product> Cow::getProduct(){
    if (habitat==1){
        std::shared_ptr<Product> res = std::shared_ptr<Product>(new CowMeat());
        return res;
    }else if(habitat==2){
        std::shared_ptr<Product> res = std::shared_ptr<Product>(new CowMilk());
        return res;
    }else{
        throw std::runtime_error("Ga mungkin bang");
    }
}

std::string Cow::render(){
    return "O";
}