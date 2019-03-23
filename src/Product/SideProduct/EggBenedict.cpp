#include <Product/SideProduct/EggBenedict.h>

EggBenedict::EggBenedict():SideProduct(ProductType::EggBenedictType,600){
}


LinkedList<std::shared_ptr<Product>> EggBenedict::getRecipe(){
    LinkedList<std::shared_ptr<Product>> recipe;
    recipe.addFirst(std::shared_ptr<Product>(new DuckEgg()));
    recipe.addFirst(std::shared_ptr<Product>(new RabbitMeat()));
    recipe.addFirst(std::shared_ptr<Product>(new GoatMilk()));
    return recipe;   
}

std::string EggBenedict::render(){
    return "Egg Benedict";
}