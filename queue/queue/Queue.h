#include <iostream>

using namespace std;

template <typename T>
class Queue{
private:
  int size;
  int front;
  int rear;
  T* array;

public:
  Queue(int size){
    this -> size = size;
    array = new T[size];
    front = 0;
    rear = -1;
  }

  void setSize(int size){
    this -> size = size;
  }

  int getSize(){
    return this -> size;
  }

  void setArray(T* array){
    this -> array = array;
  }

  T* getArray(){
    return this -> array;
  }

  void setFront(int front){
    this -> front = front;
  }

  int getFront(){
    return this -> front;
  }

  void setRear(int rear){
    this -> rear = rear;
  }

  int getRear(){
    return this -> rear;
  }

  void display(){
    for(int i = front; i <= rear; i++){
      cout<<array[i]<<" ";
    }
    cout<<endl;
  }

  bool isFull(){
    if(rear == size - 1){
      return true;
    } else {
      return false;
    }
  }

  bool isEmpty(){
    if(front == 0 && rear == -1 || rear == front - 1){
      return true;
    } else {
      return false;
    }
  }

  void enqueue(T data){
    if(isFull()){
      cout<<"overflow!"<<endl;
    } else {
      rear++;
      array[rear] = data;
    }
  }

  T dequeue(){
    if(isEmpty()){
      return -1;
    } else {
      T data = array[front];
      front++;
      return data;
    }
  }
};