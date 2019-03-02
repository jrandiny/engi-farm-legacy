#include <FarmAnimal/Cow.h>
#include <iostream>

Cow::Cow(int type):FarmAnimal(5,type){
    posX=0;
    posY=0;
    eatStatus=false;
}

String Cow::speak(){
    return "Moooooooo..!";
}

FarmProduct Cow::getProduct(){
    if (habitat.getType()==1){
        CowMeat res;
        return res;
    }else if(habitat.getType()==2){
        CowMilk res;
        return res;
    }
}