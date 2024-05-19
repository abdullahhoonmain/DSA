#include <iostream>
#include"CircularQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
 CircularQueue<int> q1(3);
 q1.enqueue(2);
 q1.enqueue(4);
 q1.enqueue(6);
 cout<<"Dequeue:"<<endl;
 cout<<q1.dequeue()<<endl;
 q1.enqueue(11);
cout<<"Dequeue:"<<endl;
 while(!q1.isEmpty()){
 	cout<<q1.dequeue()<<endl;
 }
	
	return 0;
}
