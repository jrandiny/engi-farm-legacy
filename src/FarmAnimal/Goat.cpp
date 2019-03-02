#include <FarmAnimal/Goat.h>
#include <iostream>

Goat::Goat(int type):FarmAnimal(5),habitat(0,0,type){
    posX=0;
    posY=0;
    eatStatus=false;
}

String Goat::speak(){
    return "Blet blet..!";
}

FarmProduct Goat::getProduct(){
    if (habitat.getType()==1){
        GoatMeat res;
        return res;
    }else if(habitat.getType()==2){
        GoatMilk res;
        return res;
    }
}