#include <iostream>
#include <string>
#include <cctype>
using namespace std;

template <class T>
class Stack {
private:
    T* array;
    int size;
    int top;

public:
    Stack(int size) {
        this->size = size;
        array = new T[size];
        top = -1;
    }

    ~Stack() {
        delete[] array;
    }

    void setTop(int top) {
        this->top = top;
    }

    void setSize(int size) {
        this->size = size;
    }

    void setArray(T* array) {
        this->array = array;
    }

    int getTop() {
        return top;
    }

    int getSize() {
        return size;
    }

    T* getArray() {
        return array;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    T topValue() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return array[top];
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << array[i] << endl;
        }
        cout << endl;
    }

    void push(T data) {
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            array[++top] = data;
        }
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return T(); // Return default-constructed T
        } else {
            return array[top--];
        }
    }

    string reverseString(string str) {
        string reversestr = "";
        Stack<char> stack(str.length());
        for (int i = 0; i < str.length(); i++) {
            stack.push(str[i]);
        }
        while (!stack.isEmpty()) {
            reversestr += stack.pop();
        }
        return reversestr;
    }

    bool isOperand(char c) {
        return isalnum(c);
    }

    int precedence(char c) {
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

    bool isBalanced(string expression) {
        Stack<char> stack(expression.length());
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

    int postfixEvaluation(string expression) {
        Stack<int> stack(expression.length());
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            if (isalnum(c)) {
                stack.push(c - '0'); // Assuming single-digit operands for simplicity
            } else {
                int a = stack.pop();
                int b = stack.pop();
                int result;
                switch (c) {
                    case '+': result = b + a; break;
                    case '-': result = b - a; break;
                    case '*': result = b * a; break;
                    case '/': result = b / a; break;
                    default: throw invalid_argument("Invalid operator");
                }
                stack.push(result);
            }
        }
        return stack.pop();
    }

    string infixToPostfix(string infix) {
        Stack<char> stack(infix.length());
        string postfix = "";
        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];
            if (isOperand(c)) {
                postfix += c;
            } else if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                while (!stack.isEmpty() && stack.topValue() != '(') {
                    postfix += stack.pop();
                }
                stack.pop(); // Pop the '('
            } else {
                while (!stack.isEmpty() && precedence(stack.topValue()) >= precedence(c)) {
                    postfix += stack.pop();
                }
                stack.push(c);
            }
        }
        while (!stack.isEmpty()) {
            postfix += stack.pop();
        }
        return postfix;
    }

    string infixToPrefix(string infix) {
    	
    	string reverse1= "";
        for(int i=infix.length()-1; i>=0; i--)
        {
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
        string reverse2= "";
        for(int i=prefix.length()-1; i>=0; i--)
        {	
        	reverse2+= prefix[i];
		}
        return reverse2;
    }

    string postfixToInfix(string postfix) {
        Stack<string> stack(postfix.length());
        for (int i = 0; i < postfix.length(); i++) {
            char c = postfix[i];
            if (isOperand(c)) {
                stack.push(string(1, c));
            } else {
                string a = stack.pop();
                string b = stack.pop();
                stack.push('(' + b + c + a + ')');
            }
        }
        return stack.pop();
    }

    string postfixToPrefix(string postfix) {
        Stack<string> stack(postfix.length());
        for (int i = 0; i < postfix.length(); i++) {
            char c = postfix[i];
            if (isOperand(c)) {
                stack.push(string(1, c));
            } else {
                string a = stack.pop();
                string b = stack.pop();
                stack.push(c + b + a);
            }
        }
        return stack.pop();
    }

    string prefixToInfix(string prefix) {
        Stack<string> stack(prefix.length());
        for (int i = prefix.length() - 1; i >= 0; i--) {
            char c = prefix[i];
            if (isOperand(c)) {
                stack.push(string(1, c));
            } else {
                string a = stack.pop();
                string b = stack.pop();
                stack.push('(' + a + c + b + ')');
            }
        }
        return stack.pop();
    }

    string prefixToPostfix(string prefix) {
        Stack<string> stack(prefix.length());
        for (int i = prefix.length() - 1; i >= 0; i--) {
            char c = prefix[i];
            if (isOperand(c)) {
                stack.push(string(1, c));
            } else {
                string a = stack.pop();
                string b = stack.pop();
                stack.push(a + b + c);
            }
        }
        return stack.pop();
    }
};


