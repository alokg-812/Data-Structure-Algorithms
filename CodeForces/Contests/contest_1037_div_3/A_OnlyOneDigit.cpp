/*
 link to question:
 https://codeforces.com/contest/2126/problem/A
*/

#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr;
        while(n>0){
            int d = n%10;
            arr.push_back(d);
            n=n/10;
        }
        sort(arr.begin(), arr.end());
        cout<<arr[0]<<endl;
    }
}
