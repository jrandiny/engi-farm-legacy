#include <FarmAnimal/Rabbit.h>
#include <iostream>

Rabbit::Rabbit():FarmAnimal(5),habitat(0,0,2){
    posX=0;
    posY=0;
    eatStatus=false;
}

String Rabbit::speak(){
    return "Purr purr..!";
}

FarmProduct Rabbit::getProduct(){
    RabbitMeat res;
    return res;
}