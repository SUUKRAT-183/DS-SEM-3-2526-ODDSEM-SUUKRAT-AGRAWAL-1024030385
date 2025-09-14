#include <iostream>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') 
        return 1;
    else if (op == '*' || op == '/') 
        return 2;
    else if (op == '^') 
        return 3;
    return 0;
}

int main() {
    char expr[100];
    cout << "Enter an infix expression: ";
    cin >> expr;

    char stack[100];
    int top = -1;
    string postfix = "";

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        
        else if (ch == '(' || ch == '{' || ch == '[') {
            top++;
            stack[top] = ch;
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            while (top != -1 && (stack[top] != '(' && stack[top] != '{' && stack[top] != '[')) {
                postfix += stack[top];
                top--;
            }
            if (top != -1) {
                top--;
            }
        }

        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix += stack[top];
                top--;
            }
            top++;
            stack[top] = ch;
        }
    }

    while (top != -1) {
        postfix += stack[top];
        top--;
    }

    cout << "Postfix expression is: " << postfix << endl;

    return 0;
}
