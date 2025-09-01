#include <iostream>
#include <string>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    char stack[100];
    int top = -1;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            top++;
            stack[top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatching(stack[top], ch)) {
                cout << "Expression is NOT balanced." << endl;
                return 0;
            } else {
                top--;
            }
        }
    }

    if (top == -1)
        cout << "Expression is balanced." << endl;
    else
        cout << "Expression is NOT balanced." << endl;

    return 0;
}
