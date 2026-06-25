// https://www.codechef.com/problems/MAKESUB


#include <bits/stdc++.h>
using namespace std;

int check(int n, string str){
    int cnt0=0,cnt1=0;
    for(char i:str){
        if(i=='0') cnt0++;
        else cnt1++;
    }
    if(cnt0==n) return 0;
    else{
        int pos1=0, posL=0;
        for(int i = 0;i<n;i++){
            if(str[i]=='1'){
                pos1=i;
                break;
            }
        }
        for(int i = n-1;i>=0;i--){
            if(str[i]=='1'){
                posL=i;
                break;
            }
        }
        return ((posL- pos1 + 1) - cnt1);
    }
    return 0;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>arr(n);
	    string str;
	    cin>>str;
	    cout<<check(n,str)<<endl;
	}

}
