#include <iostream>
using namespace std;

int main() {
    char expr[100];
    cout << "Enter a postfix expression (operands as characters, operators + - * / ^, brackets allowed, no spaces): ";
    cin >> expr;
    
    string stack[100];
    int top = -1;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            string operand = "";
            operand += ch; 
            stack[++top] = operand;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (top < 1) {
                cout << "Error: Insufficient operands for operator '" << ch << "'.\n";
                return 1;
            }
            
            string b = stack[top--];
            string a = stack[top--];
            string result = "(" + a + ch + b + ")";
            
            stack[++top] = result;
        }
        else if (ch == '(' || ch == ')') {
            continue;
        }
        else {
            cout << "Error: Invalid character '" << ch << "' in expression.\n";
            return 1;
        }
    }
    
    if (top != 0) {
        cout << "Error: Invalid expression - " << (top + 1) << " values remaining on stack.\n";
    } else {
        cout << "Infix expression is: " << stack[top] << endl;
    }
    
    return 0;
}
