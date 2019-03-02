#include <LinkedList.h>
// #include "test.h"

#include <iostream>
using namespace std;

int main(){
  LinkedList<int> list;
  int pilihan=1;
  int input;
  while (pilihan != 0){
    cout<<"0. exit"<<endl;
    cout<<"1. getFirst"<<endl;
    cout<<"2. getNeff"<<endl;
    cout<<"3. setFirst*"<<endl;
    cout<<"4. isEmpty"<<endl;
    cout<<"5. isInRange"<<endl;
    cout<<"6. find"<<endl;
    cout<<"7. add"<<endl;
    cout<<"8. remove"<<endl;
    cout<<"9. get"<<endl;
    cout<<"10. print"<<endl;
    cout<<"* = inProcess"<<endl;
    cin>>pilihan;
    switch (pilihan) {
      case 1:
        // if(list.getFirst()!=nullptr){
          // cout<<"Info First: "<<list.getFirst()->getInfo()<<endl;
        // } else {
          // cout<<"null"<<endl;
        // }
        break;
      case 2:
        cout<<list.getNeff()<<endl;
        break;
      case 3:
        // cout<<"input: ";
        // cin>>input;
        // Node* p;
        break;
      case 4:
        cout<<list.isEmpty()<<endl;
        break;
      case 5:
        cout<<"Indeks: ";
        cin>>input;
        cout<<"isInRange: "<<list.isInRange(input)<<endl;
        break;
      case 6:
        cout<<"Element: ";
        cin>>input;
        input = list.find(input);
        if(input!=list.idxUndeff){
          cout<<"Element found at index "<<input<<endl;
        } else {
          cout<<"Can't find element"<<endl;
        }
        break;
      case 7:
        cout<<"Element: ";
        cin>>input;
        list.addLast(input);
        cout<<"Element added at last index"<<endl;
        break;
      case 8:
        cout<<"Element which want to be removed: ";
        cin>>input;
        if(list.find(input)!=list.idxUndeff){
          list.remove(input);
          cout<<"Element removed"<<endl;
        } else {
          cout<<"Can't find element to delete"<<endl;
        }
        break;
      case 9:
        cout<<"Element's indeks to get: ";
        cin>>input;
        if (list.isInRange(input)){
          cout<<"Element info: "<<list.get(input)<<endl;
        } else {
          cout<<"Index out of bound"<<endl;
        }
        break;
      case 10:
        list.print();
        break;
      case 0: break;
      default:
        cout<<"command not recognized"<<endl;
    }
    cout<<endl;
  }
  cout<<"bye"<<endl;
  return 0;
}
