#include <iostream>
#include <Player.h>
#include <FarmAnimal/FarmAnimal.h>
#include <FarmAnimal/Chicken.h>
#include <FarmAnimal/Duck.h>
#include <FarmAnimal/Cow.h>
#include <FarmAnimal/Goat.h>
#include <FarmAnimal/Horse.h>
#include <FarmAnimal/Rabbit.h>
#include <Product/FarmProduct/ChickenEgg.h>
using namespace std;

void PrintStatus(Player& P){
    cout<<P.getWater()<<" "<<P.getMoney()<<" "<<P.getPosX()<<" "<<P.getPosY()<<endl;
}

int main(){
    LinkedList<FarmAnimal*> Farm;
    LinkedList<std::shared_ptr<Product>> bag2;
    Farm.addLast(new Chicken());
    Farm.addLast(new Duck());
    Farm.addLast(new Horse());
    Farm.addLast(new Rabbit());
    Farm.addLast(new Cow(1));
    Farm.addLast(new Cow(2));
    Farm.addLast(new Goat(1));
    Farm.addLast(new Goat(2));
    Player P(10,500000,0,5);
    PrintStatus(P);
    Farm.get(0)->setEatStatus(true);
    P.interact(*(Farm.get(0)));
    bag2=P.getBag();
    P.getBag().print();
    for(int i=0;i<4;i++){
        P.move(i);
        PrintStatus(P);
    }
    for(int i=0;i<Farm.getNeff();i++){
        cout<<P.talk(*Farm.get(i))<<endl;
    }


    return 0;
}