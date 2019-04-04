#include <gtest/gtest.h>
#include <Player.h>
#include <FarmAnimal/Chicken.h>
#include <FarmAnimal/Cow.h>
#include <FarmAnimal/Duck.h>
#include <Cell/Land.h>
#include <Cell/Land/Coop.h>
#include <string>
#include <memory>
#include <Map.h>

TEST(Player, render){
    Player p;
    ASSERT_EQ(p.render(),"👨‍");
}

TEST(Player, constructor1){
    Player p;
    ASSERT_EQ(p.getWater(),50);
    ASSERT_EQ(p.getMoney(),0);
    ASSERT_EQ(p.getPosX(),0);
    ASSERT_EQ(p.getPosY(),0);
}

TEST(Player, constructor2){
    Player p(100,50,5,10);
    ASSERT_EQ(p.getWater(),100);
    ASSERT_EQ(p.getMoney(),50);
    ASSERT_EQ(p.getPosX(),5);
    ASSERT_EQ(p.getPosY(),10);
}

TEST(Player, move){
    Player p(0,0,5,5);
    Map map(10,10);
    std::vector<std::shared_ptr<Cell>> playerSurr = map.getSurrounding(p.getPosX(),p.getPosY());

    int posX = 5;
    int posY = 5;

    std::vector<int> dirX = {0,1,0,-1};
    std::vector<int> dirY = {-1,0,1,0};

    for(int i=0;i<3;i++){
        if(!playerSurr[i]->isOccupied()){
            p.move(i,playerSurr);
            posX += dirX[i];
            posY += dirY[i];
        }
        ASSERT_EQ(p.getPosX(),posX);
        ASSERT_EQ(p.getPosY(),posY);
    }
}

TEST(Player, talkWithAnimal){
    Player p;
    Chicken chick(0,0);
    ASSERT_EQ(p.talk(chick),"Cook-a-Doodle-Doo!");
    
}

TEST(Player, addBag){
    Player p;
    int count = 0;

    p.addBag(std::shared_ptr<Product>(new ChickenEgg()));
    p.addBag(std::shared_ptr<Product>(new ChickenEgg()));
    p.addBag(std::shared_ptr<Product>(new CowMilk()));
    std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct> bag = p.getBag();
    ASSERT_EQ(bag.size(),2);
    std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct>::iterator it = bag.begin();
    while(it!=bag.end()){
        count += it->second;
        it++;
    }
    ASSERT_EQ(count,3);
}

TEST(Player, maxBagItem){
    Player p;
    int count = 0;

    for (int i=0;i<3;i++){ // 9 item
        p.addBag(std::shared_ptr<Product>(new ChickenEgg()));
        p.addBag(std::shared_ptr<Product>(new DuckEgg()));
        p.addBag(std::shared_ptr<Product>(new CowMilk()));
    }
    p.addBag(std::shared_ptr<Product>(new ChickenEgg())); // item ke 10

    ASSERT_THROW(p.addBag(std::shared_ptr<Product>(new CowMilk())),std::runtime_error);
    std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct> bag = p.getBag();
    ASSERT_EQ(bag.size(),3);
    std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct>::iterator it = bag.begin();
    while(it!=bag.end()){
        count += it->second;
        it++;
    }
    ASSERT_EQ(count,10);
}

TEST(Player, bagItemCheck){
    Player p;
    int count = 0;
    for (int i=0;i<3;i++){
        p.addBag(std::shared_ptr<Product>(new ChickenEgg()));
        p.addBag(std::shared_ptr<Product>(new DuckEgg()));
        p.addBag(std::shared_ptr<Product>(new CowMilk()));
    }
    std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct> bag = p.getBag();
    ASSERT_EQ(bag.size(),3);
    std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct>::iterator it = bag.begin();
    while(it!=bag.end()){
        std::string temp;
        switch (count)
        {
            case 0:
                temp = "Chicken Egg";
                break;
            case 1:
                temp = "Cow Milk";
                break;
            case 2:
                temp = "Duck Egg";
                break;
        }
        count++;
        ASSERT_EQ((it->first)->render(),temp);
        ASSERT_EQ((it->second),3);
        it++;
    }
}

TEST(Player, interactAnimal){
    Player p;
    Chicken chick(0,0);
    Cow tank(0,1,Cell::GrassLandType);
    Cow tanky(0,1,Cell::BarnType);
    Duck donald(1,0);
    int count =0;

    p.interact(chick);
    p.interact(tank);
    ASSERT_THROW(p.interact(tanky),std::runtime_error);
    p.interact(donald);
    chick.setEatStatus(true);
    tank.setEatStatus(true);
    tanky.setEatStatus(true);
    donald.setEatStatus(true);
    p.interact(chick);
    p.interact(tank);
    ASSERT_THROW(p.interact(tanky),std::runtime_error);
    p.interact(donald);
    std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct> bag = p.getBag();
    ASSERT_EQ(bag.size(),3);
    std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct>::iterator it = bag.begin();
    while(it!=bag.end()){
        count += it->second;
        it++;
    }
    ASSERT_EQ(count,6);
}

TEST(Player, interactWell){
    Player p(20,0,0,0);
    Well w(0,1);

    ASSERT_EQ(p.getWater(),20);
    p.interact(w);
    ASSERT_EQ(p.getWater(),50);
}

TEST(Player, interactTruck){
    Player p;
    Truck t(0,1);
    Truck t2(1,0);
    Chicken chick(0,2);
    
    for(int i=0;i<3;i++){
        p.interact(chick);
        chick.setEatStatus(true);
    }
    ASSERT_TRUE(t.isUsable());
    p.interact(t);
    ASSERT_EQ(p.getMoney(),300);
    ASSERT_FALSE(t.isUsable());
    ASSERT_THROW(p.interact(t),std::runtime_error);

    ASSERT_THROW(p.interact(t2),std::runtime_error);
}

TEST(Player, kill){
    Player p;
    Cow desk(0,1,Cell::GrassLandType);
    Cow top(0,1,Cell::BarnType);
    Truck t(0,1);

    ASSERT_THROW(p.kill(desk),std::runtime_error);
    p.kill(top);
    ASSERT_THROW(p.kill(top),std::runtime_error);
    p.interact(t);
    ASSERT_EQ(p.getMoney(),100);
    ASSERT_FALSE(desk.getDeathStatus());
    ASSERT_TRUE(top.getDeathStatus());
}

TEST(Player, grow){
    Player p;
    Land *land= new Coop(2,0);
    ASSERT_FALSE(land->haveGrass());
    p.grow(*land);
    ASSERT_TRUE(land->haveGrass());
}

TEST(Player, mix){
    Player p;
    Truck t(0,1);
    Cow tank(0,1,Cell::BarnType);
    Chicken chick(1,0);

    p.interact(chick);
    p.kill(tank);

    p.mix(Product::BeefRoladeType);
    p.interact(t);
    ASSERT_EQ(p.getMoney(),400);

    try{
        p.mix(Product::BeefRoladeType);
    } catch (std::runtime_error e){
        ASSERT_STREQ(e.what(),"Item in bag are not enough to make Beef Rolade");
    }

    for(int i=0;i<10;i++){
        chick.setEatStatus(true);
        p.interact(chick);
    }
    try{
        p.mix(Product::EggBenedictType);
    }
    catch(std::runtime_error e){
        ASSERT_STREQ(e.what(),"Bag is full");
    }
}   