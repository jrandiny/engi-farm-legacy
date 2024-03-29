/**
 * @file LinkedList.h
 * @author Back End K3
 * @brief File berisi definisi generic class LinkedList
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/** 
 * @brief Kelas generik LinkedList
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
             * @brief Konstruktor kelas Node
             * 
             */
            Node(){
                next = nullptr;
            }
            /**
             * @brief Konstruktor kelas Node dengan parameter
             * 
             * @param info Info yang akan dijadikan data
             */
            Node(T info){
                this->info = info;
                this->next = nullptr;
            }

            /**
             * @brief Mengembalikan info
             * 
             * @return Info dari node yang dimaksud
             */
            T getInfo() const{
                return info;
            }

            /**
             * @brief Mengembalikan refrensi ke info
             * 
             * @return Refrensi ke info
             */
            T& getInfoRef(){
                return info;
            }

            /**
             * @brief Mengembalikan pointer next
             * 
             * @return Pointer ke next Node
             */
            Node* getNext() const{
                return next;
            }

            /**
             * @brief Menetapkan info
             * 
             * @param info Info yang digunakan untuk update node 
             */
            void setInfo(T info){
                    this->info = info;
            }
            /**
             * @brief Menetapkan pointer next
             * 
             * @param next Pointer ke node selanjutnya
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
         * @brief Konstruktor kelas LinkedList
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
         * @brief Konstruktor kelas LinkedList dengan parameter
         * 
         * @param in LinkedList yang ingin dicopy
         * 
         * mengcopy seluruh isi dari in sehingga membuat LinkedList baru
         */
        LinkedList(const LinkedList& in){
            Node* temp = in.getFirst();

            Node* prev = nullptr;

            for(int i =0;i<in.getNeff();i++){
                Node* tempIns = new Node(temp->getInfo());
                
                if(prev==nullptr){
                    head = tempIns;
                    prev = tempIns;
                }else{
                    prev->setNext(tempIns);
                    prev = tempIns;
                }
                temp = temp->getNext();
            }

            neff = in.getNeff();
        }

        /**
         * @brief Operator overloading =
         * 
         * mengcopy seluruh Node dari in
         * 
         * @param in LinkedList yang akan di = 
         * @return LinkedList baru
         */
        LinkedList& operator=(const LinkedList& in){
            Node* temp;
            Node* next;

            temp = head;

            for(int i=0;i<neff;i++){
                next = temp->getNext();
                delete temp;
                temp = next;
            }

            temp = in.getFirst();

            Node* prev = nullptr;

            for(int i =0;i<in.getNeff();i++){
                Node* tempIns = new Node(temp->getInfo());
                
                if(prev==nullptr){
                    head = tempIns;
                    prev = tempIns;
                }else{
                    prev->setNext(tempIns);
                    prev = tempIns;
                }
                temp = temp->getNext();
            }

            neff = in.getNeff();

            return *this;
        }
        /**
         * @brief Destruktor class LinkedList
         * 
         */
        ~LinkedList(){
            Node* temp;
            Node* next;

            temp = head;

            for(int i=0;i<neff;i++){
                next = temp->getNext();
                delete temp;
                temp = next;
            }
        }

        /**
         * @brief Mengambalikan first dari LinkedList
         * 
         * @return Pointer ke Node 
         */
        Node* getFirst() const{
            return head;
        }

        /**
         * @brief Mengembalikan neff
         * 
         * @return Jumlah elemen pada LindkedList 
         */
        int getNeff() const {
            return neff;
        }

        /**
         * @brief Mengetahui apakah LinkedList kosong
         * 
         * @return True jika LinkedList kosong
         */
        bool isEmpty(){
            return head == nullptr;
        }

        /**
         * @brief Mengecek apakah indeks dalam selang yang benar
         * 
         * @param indeks Indeks yang ingin di cek
         * @return true jika indeks berada dalam selang yang benar
         */
        bool isInRange(int indeks){
            return (indeks>=firstIdx) && (indeks<neff);
        }
        /**
         * @brief Mencari indeks dari elemen yang dimasukkan
         * 
         * @param elemen Elemen yang ingin di cari indeksnya
         * @return Indeks dimana elemen ditemukan, IdxUndeff jika tidak ada
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
         * @brief Menambahkan elemen di awal LinkedList
         * 
         * @param elemen Elemen yang ingin ditambahkan
         */
        void addFirst(T elemen){
            Node* temp = new Node(elemen);
            temp->setNext(head);
            head = temp;
            neff++;
        }

        /**
         * @brief Menambahkan elemen di akhir LinkedList
         * 
         * @param elemen Elemen yang ingin di tambahkan
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
         * @brief Membuang elemen dari LinkedList
         * 
         * @param elemen Elemen yang ingin di buang dari LinkedList
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
         * @brief Mengembalikan elemen pada indeks
         * 
         * prekondisi indeks pasti isInRange
         * 
         * @param indeks Indeks yang ingin dicari
         * @return T Elemen pada posisi ke-indeks
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
        
        T& operator[](int indeks){
            int iter = indeks;
            Node* p = head;
            while(iter>firstIdx){
                p = p->getNext();
                iter--;
            } //iter==firstIdx;
            return p->getInfoRef();
        }

        /**
         * @brief Menampilkan semua elemen pada LinkedList
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
