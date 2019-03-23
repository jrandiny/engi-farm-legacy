#include <gtest/gtest.h>
#include <Cell/Cell.h>
#include <Cell/Facility/Mixer.h>
#include <Cell/Facility/Truck.h>
#include <Cell/Facility/Well.h>
#include <Cell/Land/Barn.h>
#include <Cell/Land/Coop.h>

TEST(Cell, constructor){
    Cell *barn = new Barn(5,10);
    Cell *truck = new Truck(10,5);
    ASSERT_EQ(barn->getX(),5);
    ASSERT_EQ(barn->getY(),10);
    ASSERT_FALSE(barn->isOccupied());
    ASSERT_TRUE(truck->isOccupied());
    ASSERT_EQ(barn->getType(),Cell::BarnType);
}

TEST(Cell, opSama){
    Cell *barn = new Barn(5,10);
    Cell *barnToo = new Barn(10,5);
    Cell *coop = new Coop(5,10);
    ASSERT_FALSE(*barn==*coop);
    ASSERT_TRUE(*barn==*barnToo);
}