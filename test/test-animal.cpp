#include <gtest/gtest.h>
#include <FarmAnimal/FarmAnimal.h>
#include <FarmAnimal/Chicken.h>
#include <FarmAnimal/Duck.h>
#include <FarmAnimal/Cow.h>
#include <FarmAnimal/Goat.h>
#include <FarmAnimal/Horse.h>
#include <FarmAnimal/Rabbit.h>
#include <Product/Product.h>

TEST(Animal, neff){
    LinkedList<FarmAnimal*> Farm;
    Farm.addLast(new Chicken(0,0));
    Farm.addLast(new Duck(0,0));
    Farm.addLast(new Horse(0,0));
    Farm.addLast(new Rabbit(0,0));
    Farm.addLast(new Cow(0,0,Cell::CellType::BarnType));
    Farm.addLast(new Cow(0,0,Cell::CellType::GrassLandType));
    Farm.addLast(new Goat(0,0,Cell::CellType::BarnType));
    Farm.addLast(new Goat(0,0,Cell::CellType::GrassLandType));
    ASSERT_EQ(Farm.getNeff(),8);
}       
        
TEST(Animal, speak){
    Chicken ayam(0,0);
    Duck bebek(0,0);
    Horse kuda(0,0);
    Rabbit kelinci(0,0);
    Cow sapi(0,0,Cell::CellType::BarnType);
    Goat kambing(0,0,Cell::CellType::GrassLandType);
    ASSERT_EQ(ayam.speak(), "Cook-a-Doodle-Doo!");
    ASSERT_EQ(bebek.speak(), "Quack quack..!");
    ASSERT_EQ(kuda.speak(), "Nay nay..!");
    ASSERT_EQ(kelinci.speak(), "Purr purr..!");
    ASSERT_EQ(sapi.speak(), "Moooooooo..!");
    ASSERT_EQ(kambing.speak(), "Blet blet..!");
}

TEST(Animal, render){
    Chicken ayam(0,0);
    Duck bebek(0,0);
    Horse kuda(0,0);
    Rabbit kelinci(0,0);
    Cow sapi(0,0,Cell::CellType::BarnType);
    Goat kambing(0,0,Cell::CellType::GrassLandType);   
    ASSERT_EQ(ayam.render(), "C");
    ASSERT_EQ(bebek.render(), "D");
    ASSERT_EQ(kuda.render(), "H");
    ASSERT_EQ(kelinci.render(), "R");
    ASSERT_EQ(sapi.render(), "O");
    ASSERT_EQ(kambing.render(), "G");
}

TEST(Animal, getProduct){
    Chicken ayam(0,0);
    Duck bebek(0,0);
    Horse kuda(0,0);
    Rabbit kelinci(0,0);
    Cow sapibarn(0,0,Cell::CellType::BarnType);
    Cow sapigrass(0,0,Cell::CellType::GrassLandType);
    Goat kambingbarn(0,0,Cell::CellType::BarnType);   
    Goat kambinggrass(0,0,Cell::CellType::GrassLandType);
    ASSERT_EQ(ayam.getProduct()->getType(),Product::ProductType::ChickenEggType);
    ASSERT_EQ(bebek.getProduct()->getType(),Product::ProductType::DuckEggType);
    ASSERT_EQ(kuda.getProduct()->getType(),Product::ProductType::HorseMeatType);
    ASSERT_EQ(kelinci.getProduct()->getType(),Product::ProductType::RabbitMeatType);
    ASSERT_EQ(sapibarn.getProduct()->getType(),Product::ProductType::CowMeatType);
    ASSERT_EQ(sapigrass.getProduct()->getType(),Product::ProductType::CowMilkType);
    ASSERT_EQ(kambingbarn.getProduct()->getType(),Product::ProductType::GoatMeatType);
    ASSERT_EQ(kambinggrass.getProduct()->getType(),Product::ProductType::GoatMilkType);
}

TEST(Animal, location){
    Chicken ayam(1,2);
    Duck bebek(3,4);
    Horse kuda(5,6);
    Rabbit kelinci(7,8);
    Cow sapi(9,10,Cell::CellType::BarnType);
    Goat kambing(11,12,Cell::CellType::GrassLandType);   
    ASSERT_EQ(ayam.getX(),1);
    ASSERT_EQ(ayam.getY(),2);
    ASSERT_EQ(bebek.getX(),3);
    ASSERT_EQ(bebek.getY(),4);
    ASSERT_EQ(kuda.getX(),5);
    ASSERT_EQ(kuda.getY(),6);
    ASSERT_EQ(kelinci.getX(),7);
    ASSERT_EQ(kelinci.getY(),8);
    ASSERT_EQ(sapi.getX(),9);
    ASSERT_EQ(sapi.getY(),10);
    ASSERT_EQ(kambing.getX(),11);
    ASSERT_EQ(kambing.getY(),12);
}