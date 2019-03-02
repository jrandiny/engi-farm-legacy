#include <Product/SideProduct/Meatza.h>

Meatza::Meatza(){
    recipe.addFirst(GoatMeat());
    recipe.addFirst(HorseMeat());
    recipe.addFirst(RabbitMeat());
}

LinkedList<Product> Meatza::getRecipe(){
    return recipe; //belum diimplementasikan    
}