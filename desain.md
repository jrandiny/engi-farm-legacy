# Dokumen Kelas
## Penurunan
Semua implement renderable (abstract class)

- Player
- Cell
  - Land
    - Coop
    - Grassland
    - Barn
  - Facility
    - Well
    - Mixer
    - Truck
- FarmAnimal
  - MeatProducingFarmAnimal
    - Cow
    - Goat
    - Horse
    - Rabbit
  - MilkProducingFarmAnimal
    - Cow
    - Goat
  - EggProducingFarmAnimal
    - Chicken
    - Duck
- Product
  - FarmProduct
    - ChickenEgg
    - DuckEgg
    - CowMilk
    - GoatMilk
    - CowMeat
    - GoatMeat
    - HorseMeat
    - RabbitMeat
  - SideProduct
    - BeefRolade (ChickenEgg + CowMeat) 
    - EggBenedict (DuckEgg + RabbitMeat + GoatMilk)
    - Meatza (GoatMeat + HorseMeat + RabbitMeat)

## Kelas
### Player
#### Data
```hpp
LinkedList<Product> bag;
const LinkedList<SideProduct> recipe;
int water;
int money;
int posX;
int posY;
```
#### Method
```hpp
void move(int);
void talk(FarmAnimal);
void interact(EggProducingFarmAnimal);
void interact(MilkProducingFarmAnimal);
void interact(Facility);
Product kill(MeatProducingAnimal);
void grow();
void mix(SideProduct);
```
### Cell(ABC)
#### Data
```hpp
const int x;
const int y;
```
#### Method
```hpp

```
#### Land
##### Data
```hpp

```
##### Method
```hpp

```

### FarmAnimal(ABC)
#### Data
```hpp
const timeToHungry;
int posX,posY;
```
#### Method
```hpp
bool isHungry();
virtual void speak() = 0;
virtual Product getProduct() = 0;
void moveRandom()
```

### Product (ABC)
#### Data

#### Method




## Utility
Generic class linked list
- find(T element) → int
Mengembalikan indeks dimana elemen ditemukan, -1 jika tidak ada
- isEmpty()
Mengembalikan True jika linked list kosong
- add(T element) → int
Menambahkan elemen sebagai elemen paling akhir
- remove(T element) → int
Membuang elemen dari linked list
- get(T indeks) → T
Mengembalikan elemen pada indeks

# Spesifikasi
- Untuk tugas ini buat setidaknya ​ 6 ​ (enam) kelas riil ​ FarmAnimal​ , ​ 6 ​ (enam) kelas riil FarmProduct​ , dan ​ 3​ (tiga) kelas riil SideProduct​ (total 15 kelas)
- Truck tidak bisa dipakai untuk beberapa saat setelah interact dengan truck 
- permainan berakhir saat semua hewan mati
