#include <iostream>
#include<string>
using namespace std;

int main() {
    string str;    
    cout << "Enter a string: ";
    getline(cin, str); 

    int n = str.length();

    char stack[100];  
    int top = -1;     

    for (int i = 0; i < n; i++) {
        top++;
        stack[top] = str[i];
    }

    string reversedStr = "";
    while (top >= 0) {
        reversedStr += stack[top];
        top--;
    }

    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reversedStr << endl;

    return 0;
}
