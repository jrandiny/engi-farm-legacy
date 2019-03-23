#include <gtest/gtest.h>
#include <Player.h>
#include <memory>

// TEST(Player, render){
//     Player p;
//     ASSERT_EQ(p.render(),"P");
// }

// TEST(Player, construct1){
//     Player p;
//     ASSERT_EQ(p.getWater(),0);
//     ASSERT_EQ(p.getMoney(),0);
//     ASSERT_EQ(p.getPosX(),0);
//     ASSERT_EQ(p.getPosY(),0);
// }

// TEST(Player, construct2){
//     Player p(100,50,5,10);
//     ASSERT_EQ(p.getWater(),100);
//     ASSERT_EQ(p.getMoney(),50);
//     ASSERT_EQ(p.getPosX(),5);
//     ASSERT_EQ(p.getPosY(),10);
// }

// TEST(Player, addBag){
//     Player p;
//     int count = 0;
//     p.addBag(std::shared_ptr<Product>(new ChickenEgg()));
//     p.addBag(std::shared_ptr<Product>(new ChickenEgg()));
//     p.addBag(std::shared_ptr<Product>(new CowMilk()));
//     std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct> bag = p.getBag();
//     ASSERT_EQ(bag.count(),2);
//     std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct>::iterator it = bag.begin();
//     while(it!=bag.end()){
//         count += it->second;
//     }
//     ASSERT_EQ(count,3);
// }
