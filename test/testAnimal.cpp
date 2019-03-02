#include <iostream>
#include <FarmAnimal/FarmAnimal.h>
#include <FarmAnimal/Chicken.h>
#include <FarmAnimal/Duck.h>
#include <FarmAnimal/Cow.h>
#include <FarmAnimal/Goat.h>
#include <FarmAnimal/Horse.h>
#include <FarmAnimal/Rabbit.h>

using namespace std;

int main(){
    LinkedList<FarmAnimal*> Farm;
    Farm.addLast(new Chicken());
    Farm.addLast(new Duck());
    Farm.addLast(new Horse());
    Farm.addLast(new Rabbit());
    Farm.addLast(new Cow(1));
    Farm.addLast(new Cow(2));
    Farm.addLast(new Goat(1));
    Farm.addLast(new Goat(2));
    for(int i=0;i<Farm.getNeff();i++){
        cout<<Farm.get(i)->speak()<<endl;
        cout<<Farm.get(i)->getHabitat()<<endl;
    }
    return 0;
}