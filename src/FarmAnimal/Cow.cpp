/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Cow
 * @version 0.1
 * @date 2019-03-01
 */

#include <FarmAnimal/Cow.h>
#include <iostream>

Cow::Cow(int x, int y,Cell::CellType type):FarmAnimal(x,y,5,type){
}

std::string Cow::speak(){
    return "Moooooooo..!";
}

std::shared_ptr<Product> Cow::getProduct(){
    if (habitat==Cell::BarnType){
        std::shared_ptr<Product> res = std::shared_ptr<Product>(new CowMeat());
        return res;
    }else if(habitat==Cell::GrassLandType){
        std::shared_ptr<Product> res = std::shared_ptr<Product>(new CowMilk());
        return res;
    }else{
        throw std::runtime_error("Ga mungkin bang");
    }
}

std::string Cow::render(){
    return "O";
}