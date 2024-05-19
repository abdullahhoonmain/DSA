#include <iostream>
#include "D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_6_Queue\Priority Queue\PNode.h"
template <typename T>
class PriorityQueue{
private:
  PNode<T>* front;
  PNode<T>* rear;

public:
  PriorityQueue(){
    front = rear = NULL;
  }

  void setFront(PNode<T>* front){
    this -> front = front;
  }

  PNode<T>* getFront(){
    return this -> front;
  }

  void setRear(PNode<T>* rear){
    this -> rear = rear;
  }

  PNode<T>* getRear(){
    return this -> rear;
  }

  bool isEmpty(){
    if(front == rear == NULL){
      return true;
    } else {
      return false;
    }
  }

  void display(){
    if(isEmpty()){
      cout<<"Queue is Empty!"<<endl;
    } else {
      PNode<T>* temp = front;
      while(temp != NULL){
        temp -> display();
        temp = temp -> getNext();
      }
    }
  }

  void enqueue(T data, int priority){
    PNode<T>* newNode = new PNode<T>(data,priority);
    if(isEmpty()){
      front = rear = newNode;
    } else {
      if(priority > front -> getPriority()){
        newNode -> setNext(front);
        front = newNode;
      } else if(priority < rear -> getPriority()){
        rear -> setNext(newNode);
        rear = newNode;
      } else {
        PNode<T>* temp = front;
        while(temp -> getPriority() > priority){
          temp = temp -> getNext();
        }
        temp -> setNext(newNode);
        newNode -> setNext(temp -> getNext());
      }
    }
  }

  void dequeue(){
    if(isEmpty()){
      cout<<"Queue is Empty!"<<endl;
    } else {
      PNode<T>* temp = front -> getNext();
      delete front;
      front = temp;
    }
  }

};