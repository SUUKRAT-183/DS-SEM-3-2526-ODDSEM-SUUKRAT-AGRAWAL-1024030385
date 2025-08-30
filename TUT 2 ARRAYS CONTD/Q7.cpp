#include<iostream>
using namespace std;
int main(){
    int n,arr[100],i,j,c=0;
    cout<<"Enter size of array (<=100)";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Entered Array is \n";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                c++;
            }
        }
    }    
    cout<<"Number of inversions in the entered array is - "<<c;
}