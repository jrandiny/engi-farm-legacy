#include <Product/SideProduct/BeefRolade.h>

BeefRolade::BeefRolade():SideProduct(21,400){
    recipe.addFirst(std::shared_ptr<Product>(new CowMeat()));
    recipe.addFirst(std::shared_ptr<Product>(new ChickenEgg()));
}
LinkedList<std::shared_ptr<Product>> BeefRolade::getRecipe(){
    return recipe; //belum diimplementasikan    
}

std::string BeefRolade::render(){
    return "Beef Rolade";
}