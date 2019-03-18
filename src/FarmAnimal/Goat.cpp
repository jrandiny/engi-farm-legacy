#include <FarmAnimal/Goat.h>
#include <iostream>

Goat::Goat(int type):FarmAnimal(5,type){
    posX=0;
    posY=0;
    eatStatus=false;
    deathStatus = false;
}

std::string Goat::speak(){
    return "Blet blet..!";
}

std::shared_ptr<Product> Goat::getProduct(){
    if (habitat==1){
        std::shared_ptr<Product> res = std::shared_ptr<Product>(new GoatMeat());
        return res;
    }else if(habitat==2){
        std::shared_ptr<Product> res = std::shared_ptr<Product>(new GoatMilk());
        return res;
    }else{
        throw std::runtime_error("Ga mungkin bang");
    }
}

std::string Goat::render(){
    return "G";
}