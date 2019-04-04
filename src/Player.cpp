//Kelompok: Back End K3
//Tanggal : 1/3/19

#include <Player.h>
#include <Product/SideProduct/BeefRolade.h>
#include <Product/SideProduct/EggBenedict.h>
#include <Product/SideProduct/Meatza.h>
#include <memory>

std::shared_ptr<SideProduct> Player::Resep::getRecipe(Product::ProductType id){
    if (id == Product::EggBenedictType){
        return std::shared_ptr<SideProduct>(new EggBenedict());
    } else if (id == Product::MeatzaType){
        return std::shared_ptr<SideProduct>(new Meatza());
    } else if(id == Product::BeefRoladeType){
        return std::shared_ptr<SideProduct>(new BeefRolade());
    } else {
        throw std::runtime_error("Enum Not Found");
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
    } else {
        throw std::runtime_error("Bag is full");
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

void Player::move(int arah,std::vector<std::shared_ptr<Cell>> surr){
    bool move = false;
    switch (arah)
    {
        case Map::Up:
            if(surr[Map::Up]!=nullptr && !surr[Map::Up]->isOccupied()){
                posY--;
                move = true;
                std::static_pointer_cast<Land>(surr[Map::Up])->occupy();
            }
            break;
        case Map::Right:
            if(surr[Map::Right]!=nullptr && !surr[Map::Right]->isOccupied()){
                posX++;
                move = true;
                std::static_pointer_cast<Land>(surr[Map::Right])->occupy();
            }
            break;
        case Map::Down:
            if(surr[Map::Down]!=nullptr && !surr[Map::Down]->isOccupied()){
                posY++;
                move = true;
                std::static_pointer_cast<Land>(surr[Map::Down])->occupy();
            }
            break;
        case Map::Left:
            if(surr[Map::Left]!=nullptr && !surr[Map::Left]->isOccupied()){
                posX--;
                move = true;
                std::static_pointer_cast<Land>(surr[Map::Left])->occupy();
            }
            break;
        default:
            break;
    }
    if(!move){
        throw std::runtime_error("You can't move any further");
    } else {
        std::static_pointer_cast<Land>(surr[Map::Center])->unoccupy();
    }
}

std::string Player::talk(FarmAnimal& hewan){
    return hewan.speak();
}

void Player::interact(FarmAnimal& hewan){
    if (hewan.getEatStatus() && hewan.getHabitat()!=Cell::BarnType){
        addBag(hewan.getProduct());
        hewan.setEatStatus(false);
    } else {
        throw std::runtime_error("Can't interact with animal");
    }
}
void Player::interact(Well&){
    if(water<MAX_WATER)
        water = MAX_WATER;
    else
        throw std::runtime_error("Watering can is full")
}
void Player::interact(Truck& truck){
    if(truck.isUsable()){
        if(itemNow>0){
            for (std::map<std::shared_ptr<Product>,int>::iterator it = bag.begin();it!=bag.end();it++){
                money+= it->second * (it->first)->getHarga();
            }

            bag.clear();

            truck.use(15);
            itemNow=0;
        } else {
            throw std::runtime_error("No Product to sell");
        }
    }else{
        throw std::runtime_error("Truck is currently unusable");
    }
}
void Player::kill(FarmAnimal& hewan){
    
    if (hewan.getHabitat()==Cell::BarnType && !hewan.getDeathStatus()){
        addBag(hewan.getProduct());
        hewan.setDeathStatus(true);
    } else {
        throw std::runtime_error("Can't kill animal");
    }
}

void Player::grow(Land& l){
    if(water>0){
        if(!l.haveGrass()){
            l.addGrass();
            water--;
        } else {
            throw std::runtime_error("Land already have grass");
        }
    } else {
        throw std::runtime_error("Watering can is empty");
    }
}
void Player::mix(Product::ProductType id){
    if (itemNow<MAX_ITEM_BAG){
        std::shared_ptr<SideProduct> sp;
        try{
            sp = Resep::getRecipe(id);
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
        } else {
            throw std::runtime_error("Item in bag are not enough to make "+sp->render());
        }
    } else {
        throw std::runtime_error("Bag is full");
    }
}

std::string Player::render(){
    return "👨‍";
}