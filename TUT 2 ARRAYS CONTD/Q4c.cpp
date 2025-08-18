#include <iostream>
using namespace std;

int main() {
    cout << "Enter the string:\n";
    string str;
    getline(cin, str);  
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result += c;  
        }
    }

    cout << "String without vowels: " << result;
    return 0;
}
