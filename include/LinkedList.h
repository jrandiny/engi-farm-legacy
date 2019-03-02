/**
 * @file LinkedList.h
 * @author Back End K3
 * @brief Generic class LinkedList
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/**
 * @brief Kelas abstrak LinkedList
 * @class LinkedList LinkedList.h <LinkedList.h>
 * 
 * @tparam T tipe data bentukan
 */
template <class T>
class LinkedList{
    class Node{
        private:
            T info;
            Node* next;
        public:
            /**
             * @brief Konstruktor objek node tanpa parameter
             * 
             */
            Node(){
                next = nullptr;
            }
            /**
             * @brief Konstruktor objek node dengan parameter
             * 
             * @param info info yang akan dijadikan data
             */
            Node(T info){
                this->info = info;
                this->next = nullptr;
            }

            /**
             * @brief getter untuk data info
             * 
             * @return info dari node yang dimaksud
             */
            T getInfo() const{
                return info;
            }
            /**
             * @brief getter untuk pointer ke next Node
             * 
             * @return pointer ke next Node
             */
            Node* getNext() const{
                return next;
            }

            /**
             * @brief setter untuk data info
             * 
             * @param info info yang digunakan untuk update node 
             */
            void setInfo(T info){
                    this->info = info;
            }
            /**
             * @brief setter untuk data next
             * 
             * @param next pointer ke node selanjutnya
             */
            void setNext(Node* next){
                this->next = next;
            }
    };
    private:
        Node* head;
        int neff;
    public:
        const int firstIdx = 0;
        const int idxUndeff = -1;

        /**
         * @brief Konstruktor LinkedList tanpa parameter
         * 
         * membuat LinkedList baru dengan headnya null
         * dan neffnya 0
         * 
         */
        LinkedList(){
            head = nullptr;
            neff = 0;
        }
        /**
         * @brief Konstruktor LinkedList dengan parameter
         * 
         * @param in LinkedList yang ingin dicopy
         * 
         * mengcopy seluruh isi dari in sehingga membuat LinkedList baru
         */
        LinkedList(const LinkedList& in){
            Node* temp = in.getFirst();
            while(temp!=nullptr){
                addFirst(temp->getInfo());
                temp = temp->getNext();
            }

            neff = in.getNeff();
        }

        /**
         * @brief operator overloading =
         * 
         * @param in LinkedList yang akan di = 
         * @return LinkedList baru
         * mengcopy seluruh Node dari in
         */
        LinkedList& operator=(const LinkedList& in){
            Node* temp;
            Node* next;

            temp = head;

            if(temp!=nullptr){
                next = head->getNext();

                while(next!=nullptr){
                    delete temp;
                    temp = next;
                    next = temp->getNext();
                }

                delete temp;
            }

            temp = in.getFirst();
            while(temp!=nullptr){
                addFirst(temp->getInfo());
                temp = temp->getNext();
            }

            neff = in.getNeff();

            return *this;
        }
        /**
         * @brief Destruktor untuk LinkedList
         * 
         */
        ~LinkedList(){
            Node* temp;
            Node* next;

            temp = head;

            if(temp!=nullptr){
                next = head->getNext();

                while(next!=nullptr){
                    delete temp;
                    temp = next;
                    next = temp->getNext();
                }

                delete temp;
            }
        }

        /**
         * @brief getter yang mengembalikan first
         * 
         * @return pointer ke Node 
         */
        Node* getFirst() const{
            return head;
        }
        /**
         * @brief getter dari neff 
         * 
         * @return jumlah elemen pada LindkedList 
         */
        int getNeff() const {
            return neff;
        }

        // Mengembalikan True jika linked list kosong
        /**
         * @brief mengetahui apakah LinkedList kosong
         * 
         * @return true jika LinkedList kosong
         * @return false jika LinkedList tidak kosong
         */
        bool isEmpty(){
            return head == nullptr;
        }

        /**
         * @brief mengecek apakah indeks dalam selang yang benar
         * 
         * @param indeks indeks yang ingin di cek
         * @return true jika indeks berada dalam selang yang benar
         * @return false jika indeks berada dalam selang yang salah
         */
        bool isInRange(int indeks){
            return (indeks>=firstIdx) && (indeks<neff);
        }
        // 
        /**
         * @brief mencari indeks dari elemen yang dimasukkan
         * 
         * @param elemen elemen yang ingin di cari indeksnya
         * @return int indeks dimana elemen ditemukan, IdxUndeff jika tidak ada
         */
        int find(T elemen){
            int indeks = firstIdx;
            bool found = false;
            Node *p1;
            p1 = head;
            while(p1!=nullptr && !found){
                if (p1->getInfo()==elemen){
                    found = true;
                } else {
                    p1 = p1->getNext();
                    indeks++;
                }
            } //p1 == nullptr || found == true;
            if (!found){
                indeks = idxUndeff;
            }
            return indeks;
        }
        /**
         * @brief menambahkan elemen di awal LinkedList
         * 
         * @param elemen elemen yang ingin ditambahkan
         */
        void addFirst(T elemen){
            Node* temp = new Node(elemen);
            temp->setNext(head);
            head = temp;
        }

        /**
         * @brief menambahkan elemen di akhir LinkedList
         * 
         * @param elemen elemen yang ingin di tambahkan
         */
        void addLast(T elemen){
            Node *p1,*p2,*temp;
            temp = new Node(elemen);
            p1 = head;
            p2 = nullptr;
            while (p1!= nullptr) {
                p2 = p1;
                p1 = p1->getNext();
            } //p1 == nullptr
            if (p2==nullptr) { //kosong
                head = temp;
            } else { //p2 != Nil
                p2->setNext(temp);
            }
            neff++;
        }

        /**
         * @brief membuang elemen dari LinkedList
         * 
         * @param elemen elemen yang ingin di buang dari LinkedList
         */
        void remove(T elemen){
            Node *p1,*p2;
            bool found = false;
            p1 = head;
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
                    head = p1->getNext();
                }else {
                    p2->setNext(p1->getNext());
                }
                delete p1;
                neff--;
            }
        }

        /**
         * @brief mengembalikan elemen pada indeks
         * 
         * prekondisi indeks pasti isInRange
         * 
         * @param indeks indeks yang ingin dicari
         * @return T elemen pada posisi ke-indeks
         */
        T get(int indeks){
            int iter = indeks;
            Node* p = head;
            while(iter>firstIdx){
                p = p->getNext();
                iter--;
            } //iter==firstIdx;
            return p->getInfo();
        }

        /**
         * @brief print semua elemen pada LinkedList
         * 
         */
        void print(){
            if (isEmpty()){
                std::cout<<"empty list"<<std::endl;
            } else {
                Node* p1;
                p1 = head;
                std::cout<<"list:"<<std::endl;
                while (p1!=nullptr) {
                    std::cout<<p1->getInfo()<<std::endl;
                    p1 = p1->getNext();
                } //p1 == nullptr
            }
        }
};

#endif
