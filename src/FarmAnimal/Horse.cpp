/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Horse
 * @version 0.1
 * @date 2019-03-01
 */

#include <FarmAnimal/Horse.h>
#include <iostream>
#include <memory>

Horse::Horse(int x, int y):FarmAnimal(x,y,5,Cell::CellType::BarnType){
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