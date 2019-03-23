/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Product
 * @version 0.1
 * @date 2019-03-01
 */

#include <Product/Product.h>

Product::Product(ProductType type, int _harga): type(type),harga(_harga){
}


int Product::getHarga() const{
    return this->harga;
}
Product::ProductType Product::getType() const{
    return type;
}

bool Product::operator==(Product& P){
    return P.getType()==getType();
}