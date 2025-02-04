#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n+1,-1);
    cout<<ways(n, arr)<<endl;
}