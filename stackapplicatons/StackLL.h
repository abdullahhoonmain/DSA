#include <iostream>
#include"D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_4_Stack\application of stack\Node.h"
using namespace std;
template <class T>
class StackLL {
private:
    Node<T> *top;
    
public:
    StackLL(){
        top = 0;
    }
    void push(T element);
    T pop();
    bool isEmpty();
    T topVal();
};

template <class T>
void StackLL<T>::push(T element){
    Node<T> *n = new Node<T>(element);
    if (top == 0){
        top = n;
    }else{
        n -> setNext(top);
        top = n;
    }
}

template <class T>
T StackLL<T>::pop(){
    if (top == 0) {
        cerr<<"Stack Underflow..\n";
    } else if (top->getNext()== 0){
        T element = top->getInfo();
        delete top;
        top = 0;
        return element;
    } else {
        T element = top->getInfo();
        Node<T> *temp = top->getNext();
        delete top;
        top = temp;
        return element;
    }
    // Add a return statement here to handle the case where none of the if conditions are true
    // For example, returning a default value or throwing an exception
    return 0; // Default constructor used for type T
}

template <class T>
bool StackLL<T>::isEmpty() {
    return top == 0;
}

template <class T>
T StackLL<T>::topVal() {
    if (isEmpty()) { //Context Switching
        cerr<<"Stack Underflow.. \n";
    } else {
        return top->getInfo();
    }
}