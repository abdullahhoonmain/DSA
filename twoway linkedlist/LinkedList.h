#include<iostream>
#include "D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_3_TwoWay_LinkedList\Node.h"
using namespace std;

template <class T>
class LinkedList
{
   		 private:
        Node<T>* head;
        Node<T>* tail;
    	public:
        LinkedList()
		{
            head=tail=0;
        }
       
	    void setHead(Node<T>* head); 
        Node<T>* getHead();
   		void setTail(Node<T>* tail);
   		Node<T>* getTail();
   		void addToHead(T element);
   		void addToTail(T element);
   		Node<T>* Searching(T key);
   		void Traversing();
   		void addAfter(T newE, T  oldE);
   		 void addBefore(T  newE, T oldE);
   		void removeHead();
   		 void removeTail();
   		 void removeElement(T element);
 };
 
  template <class T>
    void LinkedList<T>::setHead(Node<T>* head)
	{
        this-> head= head;
    }
    template <class T>
    Node<T>* LinkedList<T>::getHead(){
        return head;
    } 
    
        template <class T>
     void LinkedList<T>::setTail(Node<T>* tail){
        this-> tail= tail;
    }
	
	    template <class T> 
    Node<T>*LinkedList<T>::getTail()
	{
        return tail;
    }  

    template <class T>
    void LinkedList<T>::addToHead(T element)
	{
        Node<T>* node = new Node<T>(element);
        if(head==0)
		{
            head=tail=node;
        }
        else
		{
            head->setPrev(node);
            node->setNext(head);
            head=node;
        }
   } // add to head

    template <class T>
    void LinkedList<T>::addToTail(T element)
	{
        Node<T>* node= new Node<T>(element);
        if(head==0)
		{
            head=tail=node;
		}
            else
			{
                tail->setNext(node);
                node->setPrev(tail);
                tail=node;
            }
    } // add to tail

template <class T>
Node<T>* LinkedList<T>::Searching(T element) {
    if (head == nullptr) {
        cout << "Not possible. List is empty\n";
        return nullptr;
    }
    Node<T>* i = head;
    while (i != nullptr && element != i->getInfo()) {
        i = i->getNext();
    }
    if (i == nullptr) {
        cout << "not found" << endl;
        return nullptr;
    } else {
        cout << "found at: " << i << endl;
        return i;
    }
}
//searching
    
    template <class T>
    void LinkedList<T>::Traversing(){
        Node<T>* temp= head;
        while(temp != 0 ) 
		{
            cout<<"|("<<temp<<")||("<<temp->getInfo()<<")||("<<temp->getNext()<<")|\n";
            temp= temp->getNext();
    }
    }//traversing

    template <class T>
    void LinkedList<T>::addAfter(T newE, T  oldE){
        Node<T>* node= new Node<T>(newE);
        Node<T>* temp= head;
        while(temp!=0 && temp->getInfo()!=oldE){
            temp= temp->getNext();
        }
        if(head==0 || Searching(oldE) == 0){
            cout << "Element not found or List is Empty\n";
            delete  node;
        }
        else if(temp->getNext()==0){
            node->setPrev(temp);
            temp->setNext(node);
            node->setNext(0);
            tail=node;     
        }
        else{
            node->setNext(temp->getNext());
            node->setPrev(temp);
            temp->getNext()->setPrev(node);
            temp->setNext(node);
        }
    }// add after

    template <class T>
    void LinkedList<T>::addBefore(T  newE, T oldE){
        Node<T>* node= new Node<T>(newE);
        Node<T>* temp= head;
        while(temp!=0 && temp->getInfo()!=oldE)
        {
            temp= temp->getNext();
        }
        
        if(head==0 || Searching(oldE) == 0){
            cout << "Element not found or List is Empty\n";
            delete  node;
        }
        else if(temp->getNext()==0){
            node->setPrev(temp);
            temp->setNext(node);
            node->setNext(0);
            tail=node;     
        }
        else{
            node->setNext(temp);
            temp->getPrev()->setNext(node);
            node->setPrev(temp->getPrev());
            temp->setPrev(node);
        }
    }// add before
    
    template <class T>
    void LinkedList<T>::removeHead(){
        if(head==0){
            cout<<"Not possible";
        }
        else if(head==tail){
            head=tail=0;
            
        }
        else {
		
        Node<T>* temp= head->getNext();
        delete head;
        head= temp;
    }

    }// remove head
    
    template <class T>
    void LinkedList<T>::removeTail()
	{
 		if(head==0)
 		 	{
 		     	cout<<"Not possible. List is empty\n";
 		
	 	 	}
	 	
	 		else if(head==tail)
	 	 {
	 		
	 		delete tail;
	 		head=tail=0;
		 }
		 
		 else 
		 {
		 	Node<T>* temp= tail;
		 	tail=temp->getPrev();
		 	tail->setNext(nullptr);
		 	 delete temp;
		 	 
		}
		
	}
	
	template <class T>
	void LinkedList<T>::removeElement(T element)
	{
		if(head==0 || Searching(element)==0)
		{
			cout<<"Not possible, list is empty or element not found. \n";
			
		}
		
		else if(head==tail)
		{
			tail=head=0;
			
		}
		
		else
		{
			Node<T>* temp= head;
			while(temp!=0 && temp->getInfo()!=element)
			{
				temp= temp->getNext();
			}
			
			temp->setNext(temp->getPrev());
			temp->setPrev(temp->getNext());
			delete temp;
		}
	}
