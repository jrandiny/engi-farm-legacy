#include <FarmAnimal/Chicken.h>
#include <iostream>

Chicken::Chicken():FarmAnimal(5),habitat(0,0,0){
    posX=0;
    posY=0;
    eatStatus=false;
}

String Chicken::speak(){
    return "Cook-a-Doodle-Doo!";
}

FarmProduct Chicken::getProduct(){
    ChickenEgg res;
    return res;
}
