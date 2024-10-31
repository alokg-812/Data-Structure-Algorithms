#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int os=0,es=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2 == 0) es+=arr[i];
            else os += arr[i];
        }
        if(es>os) cout<<"YES\n";
        else cout<<"NO\n";

    }
}