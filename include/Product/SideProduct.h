/**
 * @file SideProduct.h
 * @author Back End K3
 * @brief File berisi definisi kelas SideProduct
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef SIDEPRODUCT_H
#define SIDEPRODUCT_H

#include <Product/Product.h>
#include <LinkedList.h>
#include <memory>

/**
 * @brief kelas abstrak SideProduct
 * @class SideProduct SideProduct.h <Product/SideProduct.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang merupakan SideProduct
 * SideProduct adalah product hasil pengolahan dari 2 Farmproduct atau lebih 
 */
class SideProduct : public Product{
  public:
    /**
     * @brief constructor object SideProduct
     * 
     */
    SideProduct();

    /**
     * @brief fungsi virtual getRecipe yang mengembalikan sebuah LinkedList product
     * 
     * @return LinkedList Product
     */
    virtual LinkedList<std::shared_ptr<Product>> getRecipe() = 0;

  protected:
    /**
     * @brief atribut kelas SideProduct berupa linkedlist product bahan untuk membuat SideProduct
     * 
     */
    LinkedList<std::shared_ptr<Product>> recipe;
};

#endif