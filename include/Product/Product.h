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
 * Kelas ini adalah parent dari semua kelas yang merupakan produk\n
 * Product adalah barang yang dihasilkan oleh animal yang memiliki nilai jual
 */
class Product: public Renderable{

  public:

    enum ProductType {BeefRoladeType,EggBenedictType,MeatzaType,ChickenEggType,CowMeatType,CowMilkType,DuckEggType,GoatMeatType,GoatMilkType,HorseMeatType,RabbitMeatType};

    /**
     * @brief Konstruktor kelas Product
     * 
     */
    Product(ProductType type, int _harga);

    /**
     * @brief Mengembalikan nilai harga suatu Product
     * 
     * @return Nilai harga jual suatu Product
     */
    int getHarga() const;
    /**
     * @brief Mengembalikan nilai type suatu Product
     * 
     * @return Nilai ProductType suatu Product
     */
    ProductType getType() const;

    /**
     * @brief Komparator kesamaan Product
     * 
     * @param P Produk yang ingin dibandingkan
     * @return True jika sama
     */
    bool operator==(Product& P);

  protected: 
    /**
     * @brief Atribut nilai type yang membedakan setiap kelas turunan Product
     */
    const ProductType type;
    /**
     * @brief Atribut nilai harga jual object
     */
    const int harga;

};

#endif