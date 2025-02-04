#include<bits/stdc++.h>
using namespace std;

// vector<int>arr(6,-1);
int stairs(int n, vector<int>arr){
    if(n<=3){
        arr[n] = n;
        return arr[n];
    }
    if(arr[n]== -1){
        arr[n] = stairs(n-1, arr)+stairs(n-2, arr);
    }
    return arr[n];
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n+1,-1);
    cout<<stairs(n, arr)<<endl;
}