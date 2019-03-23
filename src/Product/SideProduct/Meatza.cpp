#include <Product/SideProduct/Meatza.h>

Meatza::Meatza():SideProduct(ProductType::MeatzaType,500){   
}

LinkedList<std::shared_ptr<Product>> Meatza::getRecipe(){
    LinkedList<std::shared_ptr<Product>> recipe;
    recipe.addFirst(std::shared_ptr<Product>(new GoatMeat()));
    recipe.addFirst(std::shared_ptr<Product>(new HorseMeat()));
    recipe.addFirst(std::shared_ptr<Product>(new RabbitMeat()));
    return recipe;   
}

std::string Meatza::render(){
    return "Meatza";
}