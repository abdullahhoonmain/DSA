#include <iostream>
#include"D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_2_LinkedList\LinkedList.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LinkedList <int> L1;
	LinkedList <char> L2;
	L1.addToHead(13);
	L1.addToHead(5);
	L1.addToHead(7);
	L1.Traversing();
	cout<<endl;
	L2.addToTail('a');
	L2.addToTail('b');
	L2.addToTail('c');
	L2.Traversing();
	return 0;
}



