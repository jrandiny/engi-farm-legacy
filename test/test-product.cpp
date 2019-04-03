#include <gtest/gtest.h>
#include <Product/Product.h>
#include <Product/FarmProduct.h>
#include <Product/SideProduct.h>
#include <Product/FarmProduct/ChickenEgg.h>
#include <Product/FarmProduct/CowMeat.h>
#include <Product/FarmProduct/CowMilk.h>
#include <Product/FarmProduct/DuckEgg.h>
#include <Product/FarmProduct/GoatMeat.h>
#include <Product/FarmProduct/HorseMeat.h>
#include <Product/FarmProduct/RabbitMeat.h>
#include <Product/SideProduct/BeefRolade.h>
#include <Product/SideProduct/EggBenedict.h>
#include <Product/SideProduct/Meatza.h>

TEST(Product,getHarga){
    ChickenEgg chickenegg;
    CowMeat cowmeat;
    CowMilk cowmilk;
    DuckEgg duckegg;
    GoatMeat goatmeat;
    GoatMilk goatmilk;
    HorseMeat horsemeat;
    RabbitMeat rabbitmeat;
    BeefRolade beefrolade;
    EggBenedict eggbenedict;
    Meatza meatza;

    ASSERT_EQ(chickenegg.getHarga(),100);
    ASSERT_EQ(cowmeat.getHarga(),100);
    ASSERT_EQ(cowmilk.getHarga(),100);
    ASSERT_EQ(duckegg.getHarga(),100);
    ASSERT_EQ(goatmeat.getHarga(),100);
    ASSERT_EQ(goatmilk.getHarga(),100);
    ASSERT_EQ(horsemeat.getHarga(),100);
    ASSERT_EQ(rabbitmeat.getHarga(),100);
    ASSERT_EQ(beefrolade.getHarga(),400);
    ASSERT_EQ(eggbenedict.getHarga(),600);
    ASSERT_EQ(meatza.getHarga(),500);
}

TEST(Product, render){
    ChickenEgg chickenegg;
    CowMeat cowmeat;
    CowMilk cowmilk;
    DuckEgg duckegg;
    GoatMeat goatmeat;
    GoatMilk goatmilk;
    HorseMeat horsemeat;
    RabbitMeat rabbitmeat;
    BeefRolade beefrolade;
    EggBenedict eggbenedict;
    Meatza meatza;

    ASSERT_EQ(chickenegg.render(), "Chicken Egg");
    ASSERT_EQ(cowmeat.render(), "Cow Meat");
    ASSERT_EQ(cowmilk.render(), "Cow Milk");
    ASSERT_EQ(duckegg.render(), "Duck Egg");
    ASSERT_EQ(goatmeat.render(), "Goat Meat");
    ASSERT_EQ(goatmilk.render(), "Goat Milk");
    ASSERT_EQ(horsemeat.render(), "Horse Meat");
    ASSERT_EQ(rabbitmeat.render(), "Rabbit Meat");
    ASSERT_EQ(beefrolade.render(), "Beef Rolade");
    ASSERT_EQ(eggbenedict.render(), "Egg Benedict");
    ASSERT_EQ(meatza.render(), "Meatza");
}

TEST(Product, productType){
    ChickenEgg chickenegg;
    CowMeat cowmeat;
    CowMilk cowmilk;
    DuckEgg duckegg;
    GoatMeat goatmeat;
    GoatMilk  goatmilk;
    HorseMeat horsemeat;
    RabbitMeat rabbitmeat;
    BeefRolade beefrolade;
    EggBenedict eggbenedict;
    Meatza meatza;

    ASSERT_EQ(chickenegg.getType(),Product::ProductType::ChickenEggType);
    ASSERT_EQ(cowmeat.getType(),Product::ProductType::CowMeatType);
    ASSERT_EQ(cowmilk.getType(),Product::ProductType::CowMilkType);
    ASSERT_EQ(duckegg.getType(),Product::ProductType::DuckEggType);
    ASSERT_EQ(goatmeat.getType(),Product::ProductType::GoatMeatType);
    ASSERT_EQ(goatmilk.getType(),Product::ProductType::GoatMilkType);
    ASSERT_EQ(horsemeat.getType(),Product::ProductType::HorseMeatType);
    ASSERT_EQ(rabbitmeat.getType(),Product::ProductType::RabbitMeatType);
    ASSERT_EQ(beefrolade.getType(),Product::ProductType::BeefRoladeType);
    ASSERT_EQ(eggbenedict.getType(),Product::ProductType::EggBenedictType);
    ASSERT_EQ(meatza.getType(),Product::ProductType::MeatzaType);
}

TEST(Product, equalOperator){
    ChickenEgg chickenegg;
    CowMeat cowmeat;
    CowMilk cowmilk;
    DuckEgg duckegg;
    GoatMeat goatmeat;
    GoatMilk  goatmilk;
    HorseMeat horsemeat;
    RabbitMeat rabbitmeat;
    BeefRolade beefrolade;
    EggBenedict eggbenedict;
    Meatza meatza;

    ASSERT_TRUE(chickenegg.getType()==Product::ProductType::ChickenEggType);
    ASSERT_TRUE(cowmeat.getType()==Product::ProductType::CowMeatType);
    ASSERT_TRUE(cowmilk.getType()==Product::ProductType::CowMilkType);
    ASSERT_TRUE(duckegg.getType()==Product::ProductType::DuckEggType);
    ASSERT_TRUE(goatmeat.getType()==Product::ProductType::GoatMeatType);
    ASSERT_TRUE(goatmilk.getType()==Product::ProductType::GoatMilkType);
    ASSERT_TRUE(horsemeat.getType()==Product::ProductType::HorseMeatType);
    ASSERT_TRUE(rabbitmeat.getType()==Product::ProductType::RabbitMeatType);
    ASSERT_TRUE(beefrolade.getType()==Product::ProductType::BeefRoladeType);
    ASSERT_TRUE(eggbenedict.getType()==Product::ProductType::EggBenedictType);
    ASSERT_TRUE(meatza.getType()==Product::ProductType::MeatzaType);
}