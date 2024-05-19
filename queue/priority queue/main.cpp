#include<iostream>
#include"D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_6_Queue\Priority Queue\PriorityQueue.h"

using namespace std;

int main(){
  PriorityQueue<char> pq;

  pq.enqueue('a', 1);
  pq.enqueue('b', 2);
  pq.enqueue('c', 3);
  pq.enqueue('d', 4);
  pq.enqueue('e', 5);

  pq.display();

  return 0;
}
