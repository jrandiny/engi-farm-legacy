#include <Product/SideProduct/BeefRolade.h>

BeefRolade::BeefRolade(){
    recipe.addFirst(CowMeat());
    recipe.addFirst(ChickenEgg());
}
LinkedList<Product> BeefRolade::getRecipe(){
    return recipe; //belum diimplementasikan    
}