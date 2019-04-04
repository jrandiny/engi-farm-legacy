/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Chicken
 * @version 0.1
 * @date 2019-03-01
 */

#include <FarmAnimal/Chicken.h>
#include <iostream>

Chicken::Chicken(int x, int y):FarmAnimal(x,y,15,Cell::CellType::CoopType){
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