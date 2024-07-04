#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s1, s2;
        cin>>s1;
        cin>>s2;
        int min_dis = INT_MAX;
        for(int i =0;i<n-m;i++){
            int curr_dis = 0;
            for(int j = 0; j< m ;j++){
                if(s1[i+j] != s2[j]){
                    curr_dis++;
                }
            }
            if(curr_dis < min_dis){
                min_dis = curr_dis;
            }
        }
        cout<<min_dis<<endl;
    }
}