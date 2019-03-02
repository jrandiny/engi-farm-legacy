#include <FarmAnimal/Duck.h>
#include <iostream>

Duck::Duck():FarmAnimal(5),habitat(0,0,0){
    posX=0;
    posY=0;
    eatStatus=false;
}

String Duck::speak(){
    return "Quack quack..!";
}

FarmProduct Duck::getProduct(){
    DuckEgg res;
    return res;
}