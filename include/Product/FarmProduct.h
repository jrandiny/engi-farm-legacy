/**
 * @file FarmProduct.h\
 * @author Back End K3
 * @brief File berisi definisi class FarmProduct
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef FARMPRODUCT_H
#define FARMPRODUCT_H

#include <Product/Product.h>

/**
 * @brief Kelas abstrak turunan Product
 * @class FarmProduct FarmProduct.h <Product/FarmProduct.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang merupakan FarmProduct\n
 * FarmProduct adalah product yang dapat dihasilkan dari FarmAnimal
 */
class FarmProduct : public Product{
  public:
  /**
   * @brief Konstruktor kelas FarmProduct
   * 
   */
  FarmProduct();
};

#endif