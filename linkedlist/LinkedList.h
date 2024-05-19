#include<iostream>
#include"D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_2_LinkedList\Node.h"
using namespace std;
template <class T>

class LinkedList// no change
{
	private :
		Node<T> *head;
		Node<T> *tail;
		
	public:
		LinkedList(){
			tail=head=0;
		}// constructor 
		
	void setHead(Node<T> *head);
	void setTail(Node<T> *tail);
	Node<T>* getHead();
	Node<T>* getTail();

	void addToHead(T element);
	void addToTail(T element);
	void Traversing();
	Node<T>* Searching(T element);

	void addBefore(T existingE, T newE);
	void addAfter(T existingE, T newE);
	void removeHead();
	void removeTail();
    void removeGivenElement(T element);

};// EOC

template <class T>
void LinkedList<T>::setHead(Node<T> *head){
	this->head= head;
}

template <class T>
void LinkedList<T>::setTail(Node<T> *tail){
	this->tail= tail; 
}

template <class T>
Node<T>* LinkedList<T>::getHead(){
	return this->head;
}

template <class T>
Node<T>* LinkedList<T>::getTail(){
	return this->tail;
}

template <class T>
void LinkedList<T>::addToHead(T element){
	Node<T> *n= new Node<T>(element);
	if(head==0)// empty list, first node
	{
		head=tail=n;
	}
	else ////already had nodes
	{
		n->setNext(head);
		head=n;
	}
}//addto head

template <class T>
void LinkedList<T>::addToTail(T element) {
	Node<T> *node = new Node(element);
	if(head==0){
		tail=head=node;
		}
	 else{
	tail-> setNext(node);
	node-> setNext(0);
	tail= node;

	}
}// add to tail

template <class T>
void LinkedList<T>::Traversing(){
	Node<T> *i= head;
	while(i!= 0){
		cout<<i->getinfo()<<endl;
	//i->Display();
		i=i->getNext();
	}
}//traversing


template <class T>
Node<T>* LinkedList<T>::Searching(T element)
{
	if(head==0){
		cout<<"Not possible. List is empty\n";
	}
	Node<T>* i=head;
	while(*i!=0 && element!=i->getinfo())
	{
		i= i-> getNext();	
	}
	if(i=0){
		cout<<"not found"<<endl;
		return i;
	}
	
	else{
		cout<<"found at: "<<i<<endl;
		return i;
	}
	
}// searching


template <class T>
void LinkedList<T>::addAfter(T existingE, T newE){                                                                                   
	if(head==0|| Searching(existingE)==0){
			cout<<"Not Possible"<<endl;
	}
	else (
		Node<T> *node= new Node(newE);
		Node* temp=head;
		while(temp->getNext()!=0 && temp->getInfo()!=existingE){
			temp= temp->getNext();
		}
		node->setNext(temp->getNext());
		temp->setNext(node);
	)
}//Add After

template <class T>
void LinkedList<T>::addBefore(T  existingE, T newE) {
	if(head==0 || Searching(existingE)==0){
		cout<<"not possible, no such element";
	}
	else{
		Node<T> *node= new Node(newE);
		Node* temp= head;
		Node* prev = 0;
		while(temp->getNext()!=0  && temp->getInfo() != existingE ){
			prev= temp;
			temp= temp->getInfo();
	}
	prev->setNext(node);
	node->setNext(temp);

}}// add before
 
template <class T>
void LinkedList<T>::removeHead(){
	if(head==0){
		cout<<"Empty List!" << endl;
		} else if(head == tail){
			delete head;
			head=tail=0;
	}
	else(
		Node* temp= head->getNext();
		delete head;
		head=temp;
		)
}//remove head

template <class T>
void LinkedList<T>::removeTail(){
	if(head==0){
		cout<<"List is empty\n";
	}
	else if(head==tail){
		delete tail;
		head=tail=0;
	}
	else(
		Node* temp = head;
		while(temp->getNext()->getNext()!=0 ){
		temp= temp->getNext();
		}
		Node* temp2=temp->setNext();
		delete temp2;
		temp->setNext(0);
		)
}// REMOVE TAIL

template <class T>
void LinkedList<T>::removeGivenElement(T element){
	if(head==0)
	{
		cout<<"The list is Empty \n";
	}
	else(
		Node* temp = head;
		Node*  prev = 0;
		while(temp!=0 && temp-> getInfo()!= element)
		{
			prev= temp;
			temp= temp->getNext();
		}
		prev->setNext(temp->getNext());
		delete temp;
	)
}// delete selected element.





