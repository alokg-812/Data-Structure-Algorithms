#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr, int i, int sum, int n){
    if(i==n){
        cout<<sum<<endl;
        return;
    }
    print(arr, i+1, sum, n);
    print(arr, i+1, sum+arr[i], n);
    return ;
}

int main() {
    vector<int>arr = {3,5,2};
    print(arr, 0, 0, 3);
    return 0;
}