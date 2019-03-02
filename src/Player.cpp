//Kelompok: Back End K3
//Tanggal : 1/3/19

#include <Player.h>
// #include <iostream>

Player::Player(){
    water = MAX_WATER;
    money = 0;
    posX = 0;
    posY = 0;
}

Player::Player(int water, int money, int posX, int posY){
    this->water = water;
    this->money = money;
    this->posX = posX;
    this->posY = posY;
}

Player::~Player(){
    Product P_info;
    while(!bag.isEmpty()){
        P_info = bag.getFirst()->getInfo();
        bag.remove(P_info);
    }
}

LinkedList<Product> Player::getBag(){
    return bag;
}
int Player::getWater(){
    return water;
}
int Player::getMoney(){
    return money;
}
int Player::getPosX(){
    return posX;
}
int Player::getPosY(){
    return posY;
}

void Player::move(int arah){
    switch (arah)
    {
        case 0:
            posY--;
            break;
        case 1:
            posX++;
            break;
        case 2:
            posY++;
            break;
        case 3:
            posX--;
            break;
        default:
            break;
    }
}

void Player::talk(FarmAnimal& hewan){
    hewan.speak();
}

void Player::interact(FarmAnimal& hewan){
    if (hewan.getEatStatus()){
        Product temp = hewan.getProduct();
        bag.addLast(temp);
    }
}
void Player::interact(Well w){
    water = MAX_WATER;
}
void Player::interact(Truck t){
    for (int i =0;i<bag.getNeff();i++){
        money+= bag.get(0).getHarga();
        bag.remove(bag.get(0));
    }
}
void Player::kill(FarmAnimal& hewan){
    
    if (hewan.getHabitat()==2){
        Product temp = hewan.getProduct();
        bag.addLast(temp);
    }
}

void Player::grow(Land l){
    l.addGrass();
}

void Player::mix(SideProduct& sp){
    LinkedList<Product> resep = sp.getRecipe();
    LinkedList<Product> copy_bag = bag;
    int i=0;
    bool same = true;
    while(i<resep.getNeff() && same ){
        if (copy_bag.find(resep.get(i))) {
            copy_bag.remove(resep.get(i));
            resep.remove(resep.get(i));
            i++;
        } else {
            same = false;
        }
    }
    if (same){
        bag = copy_bag;
        bag.addLast(sp);
    }
    while(!copy_bag.isEmpty()){
        copy_bag.remove(copy_bag.get(0));
    }
}