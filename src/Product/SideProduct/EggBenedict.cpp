#include <Product/SideProduct/EggBenedict.h>

EggBenedict::EggBenedict():SideProduct(ProductType::EggBenedictType,600){
    recipe.addFirst(std::shared_ptr<Product>(new DuckEgg()));
    recipe.addFirst(std::shared_ptr<Product>(new RabbitMeat()));
    recipe.addFirst(std::shared_ptr<Product>(new GoatMilk()));
}


LinkedList<std::shared_ptr<Product>> EggBenedict::getRecipe(){
    return recipe; //belum diimplementasikan    
}

std::string EggBenedict::render(){
    return "Egg Benedict";
}