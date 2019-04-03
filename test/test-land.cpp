#include <gtest/gtest.h>
#include <Player.h>
#include <Cell/Cell.h>
#include <Cell/Land.h>
#include <Cell/Land/Barn.h>
#include <Cell/Land/Coop.h>
#include <Cell/Land/GrassLand.h>

TEST(Land, constructor){
    Land *grassland = new GrassLand(1,7);
    ASSERT_EQ(grassland->getX(),1);
    ASSERT_EQ(grassland->getY(),7);
    ASSERT_FALSE(grassland->isOccupied());
    ASSERT_EQ(grassland->getType(),Cell::GrassLandType);
}

TEST(Land, occupy){
    Land *grassland = new GrassLand(0,0);
    ASSERT_FALSE(grassland->isOccupied());
    grassland->occupy();
    ASSERT_TRUE(grassland->isOccupied());
    grassland->unoccupy();
    ASSERT_FALSE(grassland->isOccupied());
}

TEST(Land, grass){
    Land *coop = new Coop(0,0);
    ASSERT_FALSE(coop->haveGrass());
    coop->addGrass();
    ASSERT_TRUE(coop->haveGrass());
    coop->removeGrass();
    ASSERT_FALSE(coop->haveGrass());
}

TEST(Barn, constructor){
    Barn barn(10,6);
    ASSERT_EQ(barn.getX(),10);
    ASSERT_EQ(barn.getY(),6);
    ASSERT_EQ(barn.getType(),Cell::BarnType);
    ASSERT_FALSE(barn.isOccupied());
}

TEST(Barn, render){
    Land* barn = new Barn(1,0);
    Player p;
    ASSERT_EQ(barn->render(),"x");
    p.grow(*barn);
    ASSERT_EQ(barn->render(),"@");
}

TEST(Coop, constructor){
    Coop coop(10,6);
    ASSERT_EQ(coop.getX(),10);
    ASSERT_EQ(coop.getY(),6);
    ASSERT_EQ(coop.getType(),Cell::CoopType);
    ASSERT_FALSE(coop.isOccupied());
}

TEST(Coop, render){
    Land* coop = new Coop(1,0);
    Player p;
    ASSERT_EQ(coop->render(),"o");
    p.grow(*coop);
    ASSERT_EQ(coop->render(),"*");
}