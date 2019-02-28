//Kelompok: Back End K3
//Tanggal : 28/2/19

#ifndef linkedList_h
#define linkedList_h

#include <iostream>
using namespace std;

#define firstIdx 0
#define IdxUndeff -1

template <class T>
class linkedList{
  class Node{
    private:
      T info;
      Node* next;
    public:
      //ctor
      Node(){
        next = nullptr;
      }
      //ctor berparameter
      Node(T info){
        this->info = info;
        this->next = nullptr;
      }
      // //cctor
      // Node(const Node& A){
      //   info = A.info;
      //   next = A.next;
      // }
      // ~Node();
      //operator =
      // Node& operator=(const Node& A){
      //   info = A.info;
      //   next = A.next;
      // }

      //getter
      T getInfo() const{
        return info;
      }
      Node* getNext() const{
        return next;
      }

      //setter
      void setInfo(T info){
          this->info = info;
      }
      void setNext(Node* next){
        this->next = next;
      }
  };
  private:
    Node* First;
    int neff;
  public:
    //ctor
    linkedList(){
      First = nullptr;
      neff = 0;
    }
    //cctor
    // LinkedList(const LinkedList&);
    //dtor
    // ~LinkedList(){
    //   // delete First;
    //   cout<<"test"<<endl;
    // }
    //operator =
    // LinkedList& operator= (const LinkedList&);

    //getter
    Node* getFirst() const{
      return First;
    }

    int getNeff() const {
      return neff;
    }

    //setter
    // void setFirst(Node* n){
    //   First = n;
    // }

    // Mengembalikan True jika linked list kosong
    bool isEmpty(){
      return First == nullptr;
    }

    // Mengembalikan True jika indeks berada dalam selang yang benar
    bool isInRange(int indeks){
      return (indeks>=firstIdx) && (indeks<neff);
    }
    // Mengembalikan indeks dimana elemen ditemukan, IdxUndeff jika tidak ada
    int find(T elemen){
      int indeks = firstIdx;
      bool found = false;
      Node *p1,*p2;
      p1 = First;
      p2 = nullptr;
      while(p1!=nullptr && !found){
        if (p1->getInfo()==elemen){
          found = true;
        } else {
          p2 = p1;
          p1 = p1->getNext();
          indeks++;
        }
      } //p1 == nullptr || found == true;
      if (!found){
        indeks = IdxUndeff;
      }
      return indeks;
    }

    // Menambahkan elemen sebagai elemen paling akhir
    void add(T elemen){
      Node *p1,*p2,*temp;
      temp = new Node(elemen);
      p1 = First;
      p2 = nullptr;
      while (p1!= nullptr) {
        p2 = p1;
        p1 = p1->getNext();
      } //p1 == nullptr
      if (p2==nullptr) { //kosong
        First = temp;
      } else { //p2 != Nil
        p2->setNext(temp);
      }
      neff++;
    }

    // Membuang elemen dari linked list
    void remove(T elemen){
      Node *p1,*p2;
      bool found = false;
      p1 = First;
      p2 = nullptr;
      while(p1!=nullptr && !found){
        if (p1->getInfo()==elemen){
          found = true;
        } else {
          p2 = p1;
          p1 = p1->getNext();
        }
      } //found || p1 == nullptr
      if (found){
        if(p2==nullptr){
          First = p1->getNext();
        }else {
          p2->setNext(p1->getNext());
        }
        delete p1;
        neff--;
      }
    }

    // Mengembalikan elemen pada indeks
    // asumsi indeks sudah di dalam batas
    T get(int indeks){
      int iter = indeks;
      Node* p = First;
      while(iter>firstIdx){
        p = p->getNext();
        iter--;
      } //iter==firstIdx;
      return p->getInfo();
    }

    // Menampilkan semua elemen list
    void print(){
      if (isEmpty()){
        cout<<"empty list"<<endl;
      } else {
        Node* p1;
        p1 = First;
        cout<<"list:"<<endl;
        while (p1!=nullptr) {
          cout<<p1->getInfo()<<endl;
          p1 = p1->getNext();
        } //p1 == nullptr
      }
    }
};

#endif
