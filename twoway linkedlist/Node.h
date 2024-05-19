#include <iostream>
using namespace std;

template <class T>
class Node{
private:
    T info;
    Node* next;
    Node* prev;
public:
    Node(T info){
        this->info= info;
        next = nullptr;
        prev = nullptr;
    }
    
    T getInfo();
    void setInfo(T info);
    void setNext(Node* next);
    Node<T>* getNext();
    Node<T>* getPrev();
    void setPrev(Node* prev);
    void Display();

   
};

	template <class T>
    T Node<T>::getInfo(){
        return info;
    }
    template <class T>
    void Node<T>::setInfo(T info){
         this-> info= info;
    }
    template <class T>
    void Node<T>::setNext(Node* next){
        this-> next = next;
    }
	template <class T>
    Node<T>* Node<T>::getNext(){
        return  next;
    }
    template <class T>
    void Node<T>::setPrev(Node* prev){
        this-> prev = prev;
    }
	template <class T>
    Node<T>* Node<T>::getPrev(){
        return  prev;
    }
	template <class T>
    void Node<T>::Display()
    {
        cout<<"|("<<this->getPrev()<<")| |("<<this->getInfo()<<")| |("<<this->getNext()<<")|"<<endl;
    }

