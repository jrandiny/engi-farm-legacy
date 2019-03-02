/**
 * @file FarmProduct.h\
 * @author Back End K3
 * @brief file berisi definisi kelas FarmProduct
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef FARMPRODUCT_H
#define FARMPRODUCT_H

#include <Product/Product.h>

/**
 * @brief Kelas abstrak FarmProduct
 * @class FarmProduct FarmProduct.h <Product/FarmProduct.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang merupakan FarmProduct
 * FarmProduct adalah product yang dapat dihasilkan dari FarmAnimal
 */
class FarmProduct : public Product{
  public:
  /**
   * @brief contructor untuk objek FarmProduct
   * 
   */
  FarmProduct();
};

#endif