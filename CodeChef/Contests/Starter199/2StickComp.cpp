// https://www.codechef.com/START199D/problems/STICKCOMP

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++) cin>>arr[i];
        int idx=1;
        int bri = arr[0];
        for(int i = 1;i<n;i++){
            if(arr[i] > bri){
                bri = arr[i];
                idx = i+1;
            }
        }
        cout<<idx<<endl;
    }
}
