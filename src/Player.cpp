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
    itemNow = 0;
}

Player::Player(int water, int money, int posX, int posY){
    this->water = water;
    this->money = money;
    this->posX = posX;
    this->posY = posY;
    itemNow = 0;
}


std::map<std::shared_ptr<Product>,int, Player::cmpSharedPtrProduct> Player::getBag(){
    return bag;
}

void Player::addBag(std::shared_ptr<Product> p){
    if (itemNow<MAX_ITEM_BAG){
        std::map<std::shared_ptr<Product>,int>::iterator found=bag.find(p);
        if(found!=bag.end()){
            found->second++;
        }else{
            bag.insert(std::pair<std::shared_ptr<Product>,int>(p,1));
        }
        itemNow++;
    }
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
    if (hewan.getEatStatus() && hewan.getHabitat()!=Cell::BarnType){
        addBag(hewan.getProduct());
        hewan.setEatStatus(false);
    }
}
void Player::interact(Well&){
    water = MAX_WATER;
}
void Player::interact(Truck& truck){
    if(truck.isUsable()){
        for (std::map<std::shared_ptr<Product>,int>::iterator it = bag.begin();it!=bag.end();it++){
            money+= it->second * (it->first)->getHarga();
        }

        bag.clear();

        truck.use(15);
        itemNow=0;
    }else{
        throw std::runtime_error("Truck is currently unusable");
    }
}
void Player::kill(FarmAnimal& hewan){
    
    if (hewan.getHabitat()==Cell::BarnType){
        addBag(hewan.getProduct());
        hewan.setDeathStatus(true);
    } else {
        throw std::runtime_error("Can't kill animal not classified as meatproducing");
    }
}

void Player::grow(Land& l){
    l.addGrass();
}
void Player::mix(std::string nama){
    if (itemNow<MAX_ITEM_BAG){

        std::shared_ptr<SideProduct> sp;
        try{
            sp = Resep::getRecipe(nama);
        } catch (std::runtime_error e){
            throw std::runtime_error(e.what());
        }
        LinkedList<std::shared_ptr<Product>> resep = sp->getRecipe();
        int i=0;
        bool same = true;
        while(same && i <resep.getNeff()){
            same = bag.end()!= bag.find(resep.get(i));
            i++;
        }

        if (same){
            for (int j=0;j<i;j++){
                std::map<std::shared_ptr<Product>,int>::iterator iter = bag.find(std::shared_ptr<Product>(resep.get(j)));
                if(iter->second==1){
                    bag.erase(iter->first);
                }else{
                    iter->second--;
                }
            }
            addBag(sp);
        }
    }
}

std::string Player::render(){
    return "P";
}