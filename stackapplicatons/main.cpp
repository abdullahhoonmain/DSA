#include <iostream>
#include<cctype>
#include<stdlib.h>
#include"D:\Other Stuff\OneDrive\Documents\University\Semester 3\DSA\code\W_4_Stack\application of stack\StackLL.h"
using namespace std;

string reverseString(const string &input);
void postfixEvaluation(string postfix);
void decimalToBinary(int num);
void infixToPostfix(string infix);
int precfun(char option) {
    if (option == '^') {
        return 3;
    } else if (option == '*' || option == '/') {
        return 2;
    } else if (option == '+' || option == '-') {
        return 1;
    } else {
        return -1;
    }
}


void infixToPostfix(string infix) {
    StackLL<char> stack1;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        if (isalpha(infix[i])) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            stack1.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!stack1.isEmpty() && stack1.topVal() != '(') {
                postfix += stack1.topVal();
                stack1.pop();
            }
            if (!stack1.isEmpty()) {
                stack1.pop(); // Pop the '('
            }
        } else {
            while (!stack1.isEmpty() && precfun(stack1.topVal()) >= precfun(infix[i])) {
                postfix += stack1.topVal();
                stack1.pop();
            }
            stack1.push(infix[i]);
        }
    }
           while (!stack1.isEmpty()) {
        postfix += stack1.topVal();
        stack1.pop();
    }

    cout << "Here is the postfix expression: " << postfix << endl;
}


void infixToPrefix(string infix) {
    StackLL<char> stack1;
    string reverseinfix = reverseString(infix);
    string postfix = infixToPostfix(reverseinfix);

    string prefix = "";
    for (int i = postfix.length() - 1; i >= 0; i--) {
        if (isalpha(postfix[i])) {
            stack1.push(postfix[i]);
        } else {
            string operand1 = string(1, stack1.topVal());
            stack1.pop();
            string operand2 = string(1, stack1.topVal());
            stack1.pop();
            string result = "(" + operand1 + postfix[i] + operand2 + ")";
            stack1.push(result[0]);
        }
    }
    prefix = string(1, stack1.topVal());
    cout << "Here is the prefix expression: " << prefix << endl;
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c);
}


void postfixToPrefix(string postfix) {
    StackLL<string> stack1;

    for (char c : postfix) {
        if (isOperand(c)) {
            stack1.push(string(1, c));
        } else {
            string operand1 = stack1.pop();
            string operand2 = stack1.pop();
            string result = c + operand2 + operand1;
            stack1.push(result);
        }
    }
    cout << "Here is the prefix expression: " << stack1.pop() << endl;
}


void prefixToInfix(string prefix) {
    StackLL<string> stack1;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            stack1.push(string(1, prefix[i]));
        } else {
            string operand1 = stack1.pop();
            string operand2 = stack1.pop();
            string result = "(" + operand1 + prefix[i] + operand2 + ")";
            stack1.push(result);
        }
    }
    cout << "Here is the infix expression: " << stack1.pop() << endl;
}


void prefixToPostfix(string prefix) {
    StackLL<string> stack1;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            stack1.push(string(1, prefix[i]));
        } else {
            string operand1 = stack1.pop();
            string operand2 = stack1.pop();
            string result = operand1 + operand2 + prefix[i];
            stack1.push(result);
        }
    }
    cout << "Here is the postfix expression: " << stack1.pop() << endl;
}


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToInfix(string postfix) {
    StackLL<string> stack1;

    for (char c : postfix) {
        if (isalpha(c)) {
            stack1.push(string(1, c));
        } else if (isOperator(c)) {
            string operand2 = stack1.pop();
            string operand1 = stack1.pop();
            string result = "(" + operand1 + c + operand2 + ")";
            stack1.push(result);
        }
    }
    return stack1.pop();
}


bool isBalanced(const string &expression) {
    StackLL<char> stack;

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) {
                return false; // Unmatched closing parenthesis
            }
            char top = stack.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false; // Mismatched opening and closing parenthesis
            }
        }
    }

    return stack.isEmpty(); // Return true if stack is empty (all parentheses matched)
}



int main() {
// int opt;
// string input;
//  string postfix;
//  string infix;
// do {
//     cout << "Press 1 to convert decimal to Binary\n";
//     cout << "Press 2 for reverse string\n";
//     cout << "Press 3 to postfix evaluation\n";
//     cout << "Press 4 to convert infix to postfix\n";
//     cout << "Press 0 to exit\n";

//     cin >> opt;
//     cin.ignore(); // Clear the newline character from the input buffer

//     switch (opt) {
//         case 1:
//             cout << "Provide a number to get its binary: \n";
//             int num;
//             cin >> num;
//             cin.ignore(); // Clear the newline character from the input buffer
//             decimalToBinary(num);
//             break;
//         case 2:
//             cout << "Provide a string to reverse: ";
//             getline(cin, input, '$');
//             cout << reverseString(input);
//             break;
//         case 3:
//             cout << "Enter an expression to evaluate using postfix evaluation: ";
           
//             cin >> postfix;
//             postfixEvaluation(postfix);
//             break;
//         case 4: 
//             cout << "Enter an infix expression to convert into a postfix expression\n";
//             cin >> infix;
//             infixToPostfix(infix);
//             break;
        
//         case 0:
//             exit(-1);
//             break;
//         default:
//             cout << "Invalid option. Please try again.\n";
//             break;
//     }

// } while (opt != 0);

// return 0;


}

string reverseString(const string &input) {
    StackLL<int> stack;

	string r;
    for (int i=0;i<input.length();i++) {
        stack.push(input[i]);
    }

    string reversedString;
    while (!stack.isEmpty()) {
        reversedString += stack.pop();
    }
    return reversedString;
}

void decimalToBinary(int num) {
    if (num == 0) {
        cout << "0";
        return;
    }

    StackLL<int> stack;
    while (num != 0) {
        stack.push(num % 2);
        num /= 2;
    }

    while (!stack.isEmpty()) {
        cout << stack.pop();
    }}
    
void postfixEvaluation(string postfix){
	StackLL<double> stack1;
	for(int i=0; i<postfix.length(); i++)
	{
		if(isdigit(postfix[i]))
		{
		char c= postfix[i];
		double d= atoi(&c);
		stack1.push(d);
		}
		else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/')
		{
		double	d1= stack1.pop();
    	double	d2= stack1.pop();
			
			switch(postfix[i]){
				case '+':
					stack1.push(d2+d1);// always write second first.
					break;
				case '-':
						stack1.push(d2-d1);// always write second first.
					break;
				case '*':
						stack1.push(d2*d1);// always write second first.
					break;
				case '/':
						stack1.push(d2/d1);// always write second first.
					break;
			}//switch
		}//else
	}//loop
	cout<<endl;
	cout<<stack1.pop();

	
}// [postfix evaluation }}}
