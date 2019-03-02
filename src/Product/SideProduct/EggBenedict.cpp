#include <Product/SideProduct/EggBenedict.h>

EggBenedict::EggBenedict(){
    recipe.addFirst(DuckEgg());
    recipe.addFirst(RabbitMeat());
    recipe.addFirst(GoatMilk());
}


LinkedList<Product> EggBenedict::getRecipe(){
    return recipe; //belum diimplementasikan    
}