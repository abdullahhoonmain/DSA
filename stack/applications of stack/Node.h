#include<iostream>
using namespace std;
template<class T>
class Node {
private:
    T data;
    Node<T>* next;

public:
    Node(T info = T(), Node<T>* next = 0)
    {
    	this->data=data;
    	this->next=next;
	}
    void setData(T data);
    void setNext(Node<T>* next);
    T getData();
    Node<T>* getNext();
    void display();
};

template<class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<class T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template<class T>
T Node<T>::getData() {
    return data;
}

template<class T>
Node<T>* Node<T>::getNext() {
    return next;
}

template<class T>
void Node<T>::display() {
    cout << "|(" << this << ")|" << data << "|(" << next << ")| ";
}