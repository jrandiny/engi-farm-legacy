/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Rabbit
 * @version 0.1
 * @date 2019-03-01
 */

#include <FarmAnimal/Rabbit.h>
#include <iostream>

Rabbit::Rabbit(int x, int y):FarmAnimal(x,y,15,Cell::CellType::BarnType){
}

std::string Rabbit::speak(){
    return "Purr purr..!";
}

std::shared_ptr<Product> Rabbit::getProduct(){
    std::shared_ptr<Product> res = std::shared_ptr<Product>(new RabbitMeat());
    return res;
}

std::string Rabbit::render(){
    return "R";
}