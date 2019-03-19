/**
 * @file Product.cpp
 * @author Bak End K3
 * @brief file berisi implementasi kelas Product
 * @version 0.1
 * @date 2019-03-01
 */

#include <Product/Product.h>

Product::Product(int id, int _harga): id(id),harga(_harga){
}


int Product::getHarga() const{
    return this->harga;
}
int Product::getId() const{
    return id;
}

bool Product::operator==(Product& P){
    return P.getId()==getId();
}