#include <iostream>
#include "Stack.h"



int main() {
    Stack<int> stack(10);

    string expression = "231*+9-";
    cout << "Postfix Evaluation: " << stack.postfixEvaluation(expression) << endl;

    string infix = "a+b*c";
    cout << "Infix to Postfix: " << stack.infixToPostfix(infix) << endl;
    cout << "Infix to Prefix: " << stack.infixToPrefix(infix) << endl;

    string postfix = "abc*+";
    cout << "Postfix to Infix: " << stack.postfixToInfix(postfix) << endl;
    cout << "Postfix to Prefix: " << stack.postfixToPrefix(postfix) << endl;

    string prefix = "+a*bc";
    cout << "Prefix to Infix: " << stack.prefixToInfix(prefix) << endl;
    cout << "Prefix to Postfix: " << stack.prefixToPostfix(prefix) << endl;

    return 0;
    
    
    
    
}