#include <Product/SideProduct/Meatza.h>

Meatza::Meatza():SideProduct(23){
    recipe.addFirst(std::shared_ptr<Product>(new GoatMeat()));
    recipe.addFirst(std::shared_ptr<Product>(new HorseMeat()));
    recipe.addFirst(std::shared_ptr<Product>(new RabbitMeat()));
}

LinkedList<std::shared_ptr<Product>> Meatza::getRecipe(){
    return recipe; //belum diimplementasikan    
}

std::string Meatza::render(){
    return "Meatza";
}