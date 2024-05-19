#include<iostream>
using namespace std;
template <class T>
class CircularQueue{
	private:
	int rear;//insert at rear
	int front;//delete from front
	int size;
	T *arr;		
	public:
	CircularQueue(int size){
			rear=-1;
			front=-1;
			this->size=size;
			arr =new T[size];
		}		
	void enqueue(T element);
	T dequeue();
	bool isEmpty();
	bool isFull();
	T rearValue();
	T frontValue();
	
};


template <class T>
void CircularQueue<T>:: enqueue(T element)
{
	if ((rear==size-1&& front==0)||rear+1==front)
	{
		cout<<"Queue is full"<<endl;
	}//array full error
			
	else if(rear==-1 && front==-1){
		rear++;
     	front++;
		arr[rear]=element;	
	}//first element
	else if(front>0 && rear==size-1){
		rear=0;
		arr[rear]=element;
	}//array is partially filled by the end
	else{
		rear++;
		arr[rear]=element;
	}//	array is partially filled from start
}//enqueue


template <class T>
T CircularQueue<T>:: dequeue(){
if(rear==-1 && front==-1){
	cout<<"Underflow"<<endl;
}//array empty error

else{
	T element =arr[front];
	if(rear==front){
	rear=-1;
	front=-1;
}// only 1 element

else{
	arr[front]=0;
	front++;	
    }//more than 1 element    
    return element;
	}
}//dequeue


template <class T>
bool CircularQueue<T>:: isEmpty(){
	if(rear==-1 && front==-1){
		return true;
	}
	else{
		return false;
	}
}//isEmpty

template <class T>
bool CircularQueue<T>:: isFull(){
	if((rear==size-1&& front==0)||rear+1==front){
		return true;
	}
	else{
		return false;
	}
}//isFull


template <class T>
T CircularQueue<T>:: rearValue(){
	if(rear==-1 && front==-1){
    cout<<"Queue is empty"<<endl;
	}
	else{
		return arr[rear];
	}
}//Rear Value


template <class T>
T CircularQueue<T>:: frontValue(){
	if(rear==-1 && front==-1){
    cout<<"Queue is empty"<<endl;
	}
	else{
		return arr[front];
	}
}//Front Value
