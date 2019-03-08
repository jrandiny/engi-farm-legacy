/**
 * @file Product.h
 * @author Back End K3
 * @brief File berisi definisi class Product
 * @version 0.1
 * @date 2019-03-01 
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <Renderable.h>

/**
 * @brief Kelas abstrak turunan Renderable
 * @class Product Product.h <Product/Product.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang merupakan product\n
 * Product adalah barang yang dihasilkan oleh animal yang memiliki nilai jual
 */
class Product: public Renderable{

  public:
    /**
     * @brief Konstruktor kelas Product
     * 
     */
    Product();

    /**
     * @brief Mengembalikan nilai harga suatu product
     * 
     * @return Nilai harga jual suatu product
     */
    int getHarga();
    
    /**
     * @brief Menetapkan harga object
     * 
     * @param Harga harga objek 
     */
    void setHarga(int harga);

    /**
     * @brief Komparator kesamaan Product
     * 
     * @param P Produk yang ingin dibandingkan
     * @return True jika sama
     */
    bool operator==(Product& P);

  protected: 
    /**
     * @brief Atribut nilai harga jual object
     * 
     */
    int harga;

};

#endif