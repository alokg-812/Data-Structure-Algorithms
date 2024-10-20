#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>& arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i]<arr[i - 1]){
            return false;
        }
    }
    return true;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        if(k>=2 or check(arr,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
