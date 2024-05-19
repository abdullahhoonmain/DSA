

#include <string>
#include <cctype>
#include "Node.h"
using namespace std;

template <class T>
class LLStack {
private:
    Node<T>* top;

public:
    LLStack();

    void push(T data);
    T pop();
    T topValue();
    bool isEmpty();
    void display();
    
    string reverseString(string str);
    bool isOperand(char c);
    int precedence(char c);
    bool isBalanced(string expression);
    int postfixEvaluation(string expression);
    string infixToPostfix(string infix);
    string infixToPrefix(string infix);
    string postfixToInfix(string postfix);
    string postfixToPrefix(string postfix);
    string prefixToInfix(string prefix);
    string prefixToPostfix(string prefix);
};

template <class T>
LLStack<T>::LLStack() {
    top = nullptr;
}

template <class T>
void LLStack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data, top);
    top = newNode;
}

template <class T>
T LLStack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack UnderFlow\n";
        return T(); 
    }
    Node<T>* temp = top;
    T poppedData = temp->getData();
    top = top->getNext();
    delete temp;
    return poppedData;
}

template <class T>
T LLStack<T>::topValue() {
    if (!isEmpty()) {
        return top->getData();
    }
    return T(); 
}

template <class T>
bool LLStack<T>::isEmpty() {
    return top == nullptr;
}

template <class T>
void LLStack<T>::display() {
    Node<T>* current = top;
    while (current != nullptr) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

template <class T>
string LLStack<T>::reverseString(string str) {
    string reversestr = "";
    LLStack<char> stack;
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }
    for (int i = 0; i < str.length(); i++) {
        reversestr += stack.topValue();
        stack.pop();
    }
    return reversestr;
}

template <class T>
bool LLStack<T>::isOperand(char c) {
    return isalnum(c);
}

template <class T>
int LLStack<T>::precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

template <class T>
bool LLStack<T>::isBalanced(string expression) {
    LLStack<char> stack;
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) {
                return false; 
            }
            char top = stack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; 
            }
        }
    }
    return stack.isEmpty(); 
}

template <class T>
int LLStack<T>::postfixEvaluation(string expression) {
    LLStack<int> stack;
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (isdigit(c)) {
            stack.push(c - '0'); 
        } else {
            int a = stack.pop();
            int b = stack.pop();
            int result;
            switch (c) {
                case '+':
                    result = b + a;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '*':
                    result = b * a;
                    break;
                case '/':
                    result = b / a;
                    break;
                default:
                    cout << "Invalid argument\n";
            }
            stack.push(result);
        }
    }
    return stack.topValue();
}

template <class T>
string LLStack<T>::infixToPostfix(string infix) {
    LLStack<char> stack;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix += c;
        } else {
            if (stack.isEmpty()) {
                stack.push(c);
            } else if (precedence(c) > precedence(stack.topValue())) {
                stack.push(c);
            } else {
                while (!stack.isEmpty() && precedence(stack.topValue()) >= precedence(c)) {
                    postfix += stack.pop();
                }
                stack.push(c);
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    return postfix;
}

template <class T>
string LLStack<T>::infixToPrefix(string infix) {
    string reverse1 = "";
    for(int i = infix.length() - 1; i >= 0; i--) {
        reverse1 += infix[i];
    }
    for (int i = 0; i < reverse1.length(); i++) {
        if (reverse1[i] == '(') {
            reverse1[i] = ')';
        } else if (reverse1[i] == ')') {
            reverse1[i] = '(';
        }
    }
    string prefix = infixToPostfix(reverse1);
    string reverse2 = "";
    for(int i = prefix.length() - 1; i >= 0; i--) {
        reverse2 += prefix[i];
    }
    return reverse2;
}

template <class T>
string LLStack<T>::postfixToInfix(string postfix) {
    LLStack<string> stack;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            string op(1, c);
            stack.push(op);
        } else {
            string a = stack.pop();
            string b = stack.pop();
            string exp = "(" + b + c + a + ")";
            stack.push(exp);
        }
    }
    return stack.topValue();
}

template <class T>
string LLStack<T>::postfixToPrefix(string postfix) {
    LLStack<string> stack;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            string op(1, c);
            stack.push(op);
        } else {
            string a = stack.pop();
            string b = stack.pop();
            string exp = c + b + a;
            stack.push(exp);
        }
    }
    return stack.topValue();
}

template <class T>
string LLStack<T>::prefixToInfix(string prefix) {
    LLStack<string> stack;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            string op(1, c);
            stack.push(op);
        } else {
            string a = stack.pop();
            string b = stack.pop();
            string exp = "(" + a + c + b + ")";
            stack.push(exp);
        }
    }
    return stack.topValue();
}

template <class T>
string LLStack<T>::prefixToPostfix(string prefix) {
    LLStack<string> stack;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            string op(1, c);
            stack.push(op);
        } else {
            string a = stack.pop();
            string b = stack.pop();
            string exp = a + b + c;
            stack.push(exp);
        }
    }
    return stack.topValue();
}


