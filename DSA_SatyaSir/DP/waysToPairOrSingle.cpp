#include<bits/stdc++.h>
using namespace std;

int ways(int n, vector<int>& arr){
    if(n<=2){
        arr[n] = n;
        return arr[n];
    }
    if(arr[n]== -1){
        arr[n] = ways(n-1, arr)+(n-1)* ways(n-2, arr);
    }
    return arr[n];
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n+1,-1);
    cout<<ways(n, arr)<<endl;
}