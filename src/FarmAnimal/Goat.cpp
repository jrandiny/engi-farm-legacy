/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Goat
 * @version 0.1
 * @date 2019-03-01
 */

#include <FarmAnimal/Goat.h>
#include <iostream>

Goat::Goat(int x, int y, Cell::CellType type):FarmAnimal(x,y,5,type){
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