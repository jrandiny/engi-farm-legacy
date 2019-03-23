/**
 * @file SideProduct.h
 * @author Back End K3
 * @brief File berisi definisi class SideProduct
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef SIDEPRODUCT_H
#define SIDEPRODUCT_H

#include <Product/Product.h>
#include <LinkedList.h>
#include <memory>

/**
 * @brief kelas abstrak turunan Product
 * @class SideProduct SideProduct.h <Product/SideProduct.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang merupakan SideProduct\n
 * SideProduct adalah Product hasil pengolahan dari 2 FarmProduct atau lebih 
 */
class SideProduct : public Product{
  public:    

    /**
     * @brief Konstruktor kelas SideProduct
     * 
     */
    SideProduct(ProductType type, int _harga);

    /**
     * @brief Mengembalikan sebuah LinkedList Product
     * 
     * @return LinkedList of ProductType
     */
    virtual LinkedList<std::shared_ptr<Product>> getRecipe() = 0;
};

#endif