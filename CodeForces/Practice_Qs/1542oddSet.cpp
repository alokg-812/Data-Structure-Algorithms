#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(2*n);
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
        }
        bool flag = true;
        for(int i=1;i<2*n;i++){
            if(((arr[i-1]%2 == 0) && (arr[i]%2 == 0)) || ((arr[i-1]%2 != 0) && (arr[i]%2 != 0))) flag = false;
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";

    }
}
