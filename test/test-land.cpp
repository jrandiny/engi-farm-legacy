#include <gtest/gtest.h>
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