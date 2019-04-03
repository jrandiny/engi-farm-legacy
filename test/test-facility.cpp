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

TEST(Mixer, constructor){
    Mixer mix(5,6);
    ASSERT_EQ(mix.getX(),5);
    ASSERT_EQ(mix.getY(),6);
    ASSERT_TRUE(mix.isUsable());
    ASSERT_EQ(mix.getType(),Cell::MixerType);
    ASSERT_TRUE(mix.isOccupied());
}

TEST(Mixer, render){
    Mixer mix(5,6);
    ASSERT_EQ(mix.render(),"M");
}

TEST(Truck, constructor){
    Truck truck(3,4);
    ASSERT_EQ(truck.getX(),3);
    ASSERT_EQ(truck.getY(),4);
    ASSERT_TRUE(truck.isUsable());
    ASSERT_EQ(truck.getType(),Cell::TruckType);
    ASSERT_TRUE(truck.isOccupied());
}

TEST(Truck, render){
    Truck truck(5,6);
    ASSERT_EQ(truck.render(),"D");
}

TEST(Truck, use){
    Player p;
    FarmAnimal* cow = new Cow(1,2,Cell::BarnType);
    Truck truck(3,4);
    ASSERT_TRUE(truck.isUsable());
    p.kill(*cow);
    p.interact(truck);
    ASSERT_FALSE(truck.isUsable());
}

TEST(Well, constructor){
    Well well(10,6);
    ASSERT_EQ(well.getX(),10);
    ASSERT_EQ(well.getY(),6);
    ASSERT_TRUE(well.isUsable());
    ASSERT_EQ(well.getType(),Cell::WellType);
    ASSERT_TRUE(well.isOccupied());
}

TEST(Well, render){
    Well well(5,6);
    ASSERT_EQ(well.render(),"W");
}
