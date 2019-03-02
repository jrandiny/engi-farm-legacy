/**
 * @file Product.h
 * @author Back End K3
 * @brief File berisi definisi kelas Product
 * @version 0.1
 * @date 2019-03-01 
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <Renderable.h>

/**
 * @brief Kelas abstrak Product
 * @class Product Product.h <Product/Product.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang merupakan product
 * Product adalah barang yang dihasilkan oleh animal yang memiliki nilai jual
 */
class Product : public Renderable{

  public:
    /**
     * @brief Konstructor object Product
     * 
     */
    Product();

    /**
     * @brief fungsi get yang mengembalikan nilai harga suatu product
     * 
     * @return nilai harga jual suatu product
     */
    int getHarga();
    
    /**
     * @brief fungsi set untuk harga object
     * 
     * @param harga harga objek 
     */
    void setHarga(int harga);

    /**
     * @brief file untuk mengecek sama atau tidaknya suatu product
     * 
     * @param P produk yang ingin dibandingkan
     * @return true jika product P sama dengan product object
     * @return false jika product P tidak sama dengan product object
     */
    bool operator==(Product& P);

  protected: 
    /**
     * @brief atribut nilai harga jual object
     * 
     */
    int harga;

};

#endif