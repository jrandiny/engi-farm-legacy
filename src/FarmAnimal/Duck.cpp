/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Duck
 * @version 0.1
 * @date 2019-03-01
 */

#include <FarmAnimal/Duck.h>
#include <iostream>

Duck::Duck(int x, int y):FarmAnimal(x,y,15,Cell::CellType::CoopType){
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