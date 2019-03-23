#include <Product/SideProduct/BeefRolade.h>

BeefRolade::BeefRolade():SideProduct(ProductType::BeefRoladeType,400){
}
LinkedList<std::shared_ptr<Product>> BeefRolade::getRecipe(){
    LinkedList<std::shared_ptr<Product>> recipe;
    recipe.addFirst(std::shared_ptr<Product>(new CowMeat()));
    recipe.addFirst(std::shared_ptr<Product>(new ChickenEgg()));
    return recipe;  
}

std::string BeefRolade::render(){
    return "Beef Rolade";
}