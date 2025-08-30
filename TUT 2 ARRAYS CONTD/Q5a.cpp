#include<iostream>
using namespace std;
int main(){
    int arr[100][100],r,c,i,j,ar[100],k=0;
    cout<<"Enter number of rows and columns of matrix(<=100) \n";
    cin>>r>>c;
    cout<<"Enter a diagonal matrix\n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"Enter value at row number "<<i<<" column number "<<j<<endl;
            cin>>arr[i][j];
        }
    }
    cout<<"The entered matrix is - \n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(arr[i][j]!=0){
                ar[k]=arr[i][j];
                k++;
            }
        }
    }    
    cout<<"The resultant array is - \n";
    for(i=0;i<k;i++){
        cout<<ar[i]<<endl;
    }
}