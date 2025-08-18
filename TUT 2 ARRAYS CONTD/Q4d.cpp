#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int i,j,c,d; 
    char temp;
    cout << "Enter the string:\n";
    string str1;
    getline(cin, str1); 
    int x = str1.length();
    for(i=0;i<x;i++){
        for(j=i+1;j<x;j++){
            c=(int)str1[i];
            d=(int)str1[j];
            if(c>d){
                temp = str1[j];
                str1[j]=str1[i];
                str1[i]=temp;
            }
        }
    }
    
    cout << "Sorted string: " << str1;
    return 0;
}