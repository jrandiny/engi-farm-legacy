#include <TimerObject.h>
#include <Cell/Facility/Truck.h>
#include <FarmAnimal/Chicken.h>
#include <gtest/gtest.h>
#include <iostream>

TEST(TimerObject, truckTimer){
    Truck a(0,0);

    ASSERT_TRUE(a.isUsable());
    a.use(19);
    ASSERT_FALSE(a.isUsable());

    for(int i=0;i<20;i++){
        a.tick();
    }

    ASSERT_TRUE(a.isUsable());
    a.use(19);
    ASSERT_FALSE(a.isUsable());
    a.deactivateTimer();

    for(int i=0;i<20;i++){
        a.tick();
    }

    ASSERT_FALSE(a.isUsable());
}  

TEST(TimerObject, animalTimer){
    Chicken chick(0,0);
    ASSERT_TRUE(chick.getEatStatus());
    ASSERT_FALSE(chick.getDeathStatus());
    //timeToHungry Chicken=10
    for(int i=0;i<11;i++){//tick ke 11 berarti ketika timer=0
        chick.tick();
    }
    ASSERT_FALSE(chick.getEatStatus());
    chick.setEatStatus(true);
    
    //test setelah makan
    ASSERT_TRUE(chick.getEatStatus());
    ASSERT_FALSE(chick.getDeathStatus());
    // timeToHungry Chicken=10
    for(int i=0;i<11;i++){//tick ke 11 berarti ketika timer=0
        chick.tick();
    }
    ASSERT_FALSE(chick.getEatStatus());
    ASSERT_FALSE(chick.getDeathStatus());
    
    //timeToDeath semua animal=5
    for(int i=0;i<6;i++){//tick ke 6 berarti ketika timer=0
        chick.tick();
        ASSERT_FALSE(chick.getEatStatus());
    }
    
    ASSERT_TRUE(chick.getDeathStatus());
}

