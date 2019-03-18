/**
 * @file Product.cpp
 * @author Bak End K3
 * @brief file berisi implementasi kelas Product
 * @version 0.1
 * @date 2019-03-01
 */

#include <Product/Product.h>

/**
 * @brief constructor objek Product
 * 
 */
Product::Product(int id): id(id){
    this->harga = 0;
}

/**
 * @brief fungsi yang mengembalikan nilai harga suatu product
 * 
 * @return harga
 */
int Product::getHarga() const{
    return this->harga;
}
/**
 * @brief fungsi mengembalikan nilai id suatu product
 * 
 * @return id 
 */
int Product::getId() const{
    return id;
}

/**
 * @brief prosedur yang mengeset nilai harga suatu product
 * 
 * @param harga 
 */
void Product::setHarga(int harga){
    this->harga = harga;
}

/**
 * @brief file untuk mengecek sama atau tidaknya suatu product
 * 
 * @param Product P
 * @return true jika product P sama dengan product object
 * @return false jika product P tidak sama dengan product object
 */
bool Product::operator==(Product& P){
    return P.getId()==getId();
}