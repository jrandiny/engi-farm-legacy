#include <FarmAnimal/Horse.h>
#include <iostream>

Horse::Horse():FarmAnimal(5),habitat(0,0,2){
    posX=0;
    posY=0;
    eatStatus=false;
}

String Horse::speak(){
    return "Nay nay..!";
}

FarmProduct Horse::getProduct(){
    HorseMeat res;
    return res;
}
