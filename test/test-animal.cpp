#include <gtest/gtest.h>
#include <FarmAnimal/FarmAnimal.h>
#include <FarmAnimal/Chicken.h>
#include <FarmAnimal/Duck.h>
#include <FarmAnimal/Cow.h>
#include <FarmAnimal/Goat.h>
#include <FarmAnimal/Horse.h>
#include <FarmAnimal/Rabbit.h>

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
    Cow sapi(0,0,Cell::CellType::BarnType);
    // Cow sapi(0,0,Cell::CellType::GrassLandType);
    Goat kambing(0,0,Cell::CellType::BarnType);   
    // Goat kambing(0,0,Cell::CellType::GrassLandType);
    
      
     
}