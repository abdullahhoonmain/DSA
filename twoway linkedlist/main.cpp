#include<iostream>
#include<conio.h>
#include "D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_3_TwoWay_LinkedList\LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> L1;
	L1.addToHead(5);
	L1.addToHead(6);
	L1.addToHead(7);
	L1.Searching(6);
	L1.addToHead(8);
	L1.addAfter(2,8);
	L1.addToTail(1);
	L1.Traversing();
	cout<<"Now removing elements\n";
	L1.removeHead();
	L1.removeTail();
	L1.removeElement(6);
	L1.Traversing();


	

    return 0;
}