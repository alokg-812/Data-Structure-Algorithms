/*
 link to question:
 https://codeforces.com/contest/2126/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int cnt =0,i=0;
        while(i+k<=n){
            bool flag = true;
            for(int j=i;j<i+k;j++){
                if(arr[j] ==1){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                cnt++;
                i=i+k+1;
            }
            else i++;
        }
        cout<<cnt<<endl;
    }
}
