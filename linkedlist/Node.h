#include<iostream>
using namespace std;
template <class T>
class Node// no change
{
	private:
		T info;
		Node<T> *next;
	
	public: 
	Node(T info=0, Node<T> *next=0) {
		this->info=info;
		this->next=next;
	}//constructor
	
	
void setInfo(T info);

void setNext(Node<T> *next);
T getinfo();

Node<T>* getNext();

void Display();

};//EOC

template <class T>
void Node<T>::setInfo(T info){
	this->info= info;
}//set info

template <class T>
T Node<T>::getinfo(){
	return this->info;
}// get info

template <class T>
void Node<T>::setNext(Node<T>* next)
{
	this->next= next;
}// set next

template <class T>
Node<T>* Node<T>::getNext(){
	return this->next; 
}

template <class T>
void Node<T>::Display(){
	cout<<"|("<<this<<")|"<<this->getinfo()<<"|"<<this->getNext()<<"|"<<endl;
}// display 




















