#include <iostream>
#include<cctype>
#include<stdlib.h>
#include"D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_4_Stack\LL_Stack\LLStack.h"
using namespace std;



int main() {
	StackLL<char> S1;
	S1.push('a');
	S1.push('b');
	S1.push('c');
	char a=S1.pop();
	cout<<a<<endl;
	char b= S1.topVal();
	cout<<b<<endl;
	string ba= "abcdefg";
	string ab=reverseString(ba);
	cout<<ab<<endl;
	int num= 10;
	 decimalToBinary(num);
	
	
   
return 0;

}

    
