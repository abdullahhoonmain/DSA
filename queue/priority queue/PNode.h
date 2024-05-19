#include <iostream>

using namespace std;

template <class T>
class PNode{
private:
  T data;
  int priority;
  PNode<T>* next;

public:
  PNode(T data, int priority){
    this -> data = data;
    this -> priority = priority;
    this -> next = NULL;
  }
  void setData(T data);
  void setPriority(int priority);
  void setNext(PNode<T>* next);
  int getPriority();
  T getData();
  PNode<T>* getNext();
  void display();
  

};
template <class T>
  void PNode<T>::setData(T data){
    this -> data = data;
  }
template <class T>
  T PNode<T>::getData(){
    return this -> data;
  }
  
  template <class T>
  void PNode<T>::setPriority(int priority){
    this -> priority = priority;
  }

template <class T>
  int PNode<T>::getPriority(){
    return this -> priority;
  }

template <class T>
  void PNode<T>::setNext(PNode<T>* next){
    this -> next = next;
  }

template <class T>
  PNode<T>* PNode<T>::getNext(){
    return this -> next;
  }

template <class T>
  void PNode<T>::display(){
    cout<<"Data: "<<data<<" Priority: "<<endl;
  }
