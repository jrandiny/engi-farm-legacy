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
#include <map>
#include <Cell/Facility/Well.h>
#include <Cell/Cell.h>
#include <Cell/Land.h>
#include <Cell/Land/Coop.h>
using namespace std;

void PrintStatus(Player& P){
    cout<<P.getWater()<<" "<<P.getMoney()<<" "<<P.getPosX()<<" "<<P.getPosY()<<endl;
}

int main(){
    LinkedList<FarmAnimal*> Farm;
    map<shared_ptr<Product>,int,Player::cmpSharedPtrProduct> bag;
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
    
    
    
    // for(int i=0;i<4;i++){
    //     P.move(i);
    //     PrintStatus(P);
    // }
    for(int i=0;i<Farm.getNeff();i++){
        // cout<<P.talk(*Farm.get(i))<<endl;
        // Farm.get(i)->setEatStatus(true);
        Farm[i]->setEatStatus(true);
        P.interact(*(Farm.get(i)));
    }
    for(int i=0;i<Farm.getNeff();i++){
        // cout<<P.talk(*Farm.get(i))<<endl;
        // Farm.get(i)->setEatStatus(true);
        Farm[i]->setEatStatus(true);
        P.interact(*(Farm.get(i)));
    }
    bag=P.getBag();
    // cout<<bag.size()<<endl;
    for (auto iter:bag){
        cout<<iter.first->render()<<" "<<iter.second<<endl;
    }
    LinkedList<Cell*> map;
    LinkedList<Land*> land;
    Land *d = new Coop(1,5);
    map.addFirst(d);
    land.addFirst(d);
    cout<<map[0]->isOccupied()<<endl;
    land[0]->occupy();
    cout<<map[0]->isOccupied()<<endl;
    cout<<map[0]->render()<<endl;
    // Cell *c = new Well(1,5);
    // P.interact(c);
    PrintStatus(P);
    // Cell *d = new Coop(0,5);
    // Land *a = dynamic_cast<Land*>(d);
    // if(a!=nullptr){
    //     cout<<(*a).haveGrass()<<endl;

    // }
    // P.grow(*d);
    // cout<<d->haveGrass()<<endl;
    P.mix("EggBenedict");
    P.mix("BeefRolade");
    P.mix("Meatza");
    P.mix("EggBenedict");
    P.mix("BeefRolade");
    // P.mix("Meatza");
    bag=P.getBag();
    for (auto iter:bag){
        cout<<iter.first->render()<<" "<<iter.second<<endl;
    }
    Truck *t = new Truck(5,6);
    cout<<(*t).isUsable()<<endl;
    P.interact(*t);
    PrintStatus(P);
    bag=P.getBag();
    for (auto iter:bag){
        cout<<iter.first->render()<<" "<<iter.second<<endl;
    }
    cout<<"Truck usable = "<<(*t).isUsable()<<endl;
    for(int i =0;i<16;i++){
        t->tick();
    }
    cout<<"Truck usable = "<<(*t).isUsable()<<endl;
    return 0;
}