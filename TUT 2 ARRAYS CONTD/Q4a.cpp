#include <iostream>
#include<string.h>
using namespace std;

int main() {
    cout << "Enter the first string:\n";
    string str1;
    getline(cin, str1);   

    cout << "Enter the second string:\n";
    string str2;
    getline(cin, str2);

    string str3 = str1 + " " + str2; 
    cout << str3 << " is the concatenated string";

    return 0;
}