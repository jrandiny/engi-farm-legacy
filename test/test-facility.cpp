#include <gtest/gtest.h>
#include <Player.h>
#include <FarmAnimal/Cow.h>
#include <Cell/Cell.h>
#include <Cell/Facility.h>
#include <Cell/Facility/Mixer.h>
#include <Cell/Facility/Truck.h>
#include <Cell/Facility/Well.h>

TEST(Facility, contructor){
    Facility *well = new Well(1,7);
    ASSERT_EQ(well->getX(),1);
    ASSERT_EQ(well->getY(),7);
    ASSERT_TRUE(well->isOccupied());
    ASSERT_EQ(well->getType(),Cell::WellType);
}

TEST(Facility, isUsable){
    Player p;
    Cow cow(0,0,Cell::BarnType);
    Truck *truck = new Truck(0,5);
    ASSERT_TRUE(truck->isUsable());
    p.kill(cow);
    p.interact(*truck);
    ASSERT_FALSE(truck->isUsable());
}  