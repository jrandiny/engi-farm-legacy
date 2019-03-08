//Kelompok: Back End K3
//Tanggal : 1/3/19

#include <Player.h>
#include <Product/SideProduct/BeefRolade.h>
#include <Product/SideProduct/EggBenedict.h>
#include <Product/SideProduct/Meatza.h>
#include <memory>

std::shared_ptr<SideProduct> Player::Resep::getRecipe(std::string name){
    if (name == "EggBenedict"){
        return std::shared_ptr<SideProduct>(new EggBenedict());
    } else if (name == "Meatza"){
        return std::shared_ptr<SideProduct>(new Meatza());
    } else if(name== "BeefRolade"){
        return std::shared_ptr<SideProduct>(new BeefRolade());
    } else {
        throw std::runtime_error("No Recipe");
    }
}

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


LinkedList<std::shared_ptr<Product>> Player::getBag(){
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

std::string Player::talk(FarmAnimal& hewan){
    return hewan.speak();
}

void Player::interact(FarmAnimal& hewan){
    if (hewan.getEatStatus()){
        bag.addLast(hewan.getProduct());
    }
}
void Player::interact(Well){
    water = MAX_WATER;
}
void Player::interact(Truck){
    for (int i =0;i<bag.getNeff();i++){
        money+= bag.get(0)->getHarga();
        bag.remove(bag.get(0));
    }
}
void Player::kill(FarmAnimal& hewan){
    
    if (hewan.getHabitat()==2){
        bag.addLast(hewan.getProduct());
    } else {
        throw std::exception();
    }
}

void Player::grow(Land& l){
    l.addGrass();
}

void Player::mix(std::string nama){
    std::shared_ptr<SideProduct> sp;
    try{
        sp = Resep::getRecipe(nama);
    } catch (std::runtime_error e){
        throw std::runtime_error(e.what());
    }
    LinkedList<std::shared_ptr<Product>> resep = sp->getRecipe();
    LinkedList<std::shared_ptr<Product>> copy_bag = bag;
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

std::string Player::render(){
    return "P";
}