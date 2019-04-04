#include <gtest/gtest.h>
#include <Map.h>

TEST(Map,constructor){
    Map map(10,9);
    ASSERT_EQ(map.getMap().size(),9);
    ASSERT_EQ(map.getMap()[0].size(),10);
}

TEST(Map,getAllFarmAnimal){
    Map map(6,6);
    ASSERT_GE(map.getAllFarmAnimal().size(),6);
}

TEST(Map, oneTick){
    Map map(6,4);
    /*
        kemungkinan bentuk
        x x x x o o o o
        x x x x o o o o
        # # # # # # # #
        # # # # # # # #

        x x x x o o o o
        x x x x o o o o
        # # # # o o o o
        # # # # o o o o
    */
    int count =0;
    while(map.getAllFarmAnimal().size()>0){
        map.oneTick();
        count++;
    }
    ASSERT_LE(count,185); // 12 petak untuk 1 hewan
    ASSERT_GE(count,35); // 6 petak, 3 facility, 2 hewan
}

TEST(Map, getFacility){
    Map map(6,6);
    bool found = false;
    for(int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            try
            {
                std::shared_ptr<Mixer> mixer = map.getMixer(i,j);
                if(mixer!=nullptr)
                    found = true;
            }
            catch(const std::exception& e)
            {
            }
            
        }
    }
    ASSERT_TRUE(found);

    found = false;
    for(int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            try
            {
                std::shared_ptr<Truck> truck = map.getTruck(i,j);
                if(truck!=nullptr)
                    found = true;
            }
            catch(const std::exception& e)
            {
            }
            
        }
    }
    ASSERT_TRUE(found);

    found = false;
    for(int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            try
            {
                std::shared_ptr<Well> well = map.getWell(i,j);
                if(well!=nullptr)
                    found = true;
            }
            catch(const std::exception& e)
            {
            }
            
        }
    }
    ASSERT_TRUE(found);
    
}

