#include <iostream>
#include "D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_6_Queue\Queue\Queue.h"
using namespace std;

int main()
{

  int size;
  cout<<"enter size of array: ";
  cin>>size;

  Queue<char> q(size);

  char element;
  for(int i = 0; i < size; i++){
    cout<<"enter element: ";
    cin>>element;
    q.enqueue(element);
  }

  q.display();

  return 0;
}
