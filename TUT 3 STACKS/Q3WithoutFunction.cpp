#include <iostream>
using namespace std;

int main() {
    char expr[100];
    cout << "Enter an expression: ";
    cin >> expr;

    char stack[100];
    int top = -1;   

    //int balanced = 1; 
    bool balanced = true;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            top++;
            stack[top] = ch;
        }
     
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) { 
                balanced = false;
                break;
            }
            char topChar = stack[top];
            top--; 
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                balanced = false;
                break;
            }
        }
    }

    if (top != -1) balanced = false;

    if (balanced)
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
