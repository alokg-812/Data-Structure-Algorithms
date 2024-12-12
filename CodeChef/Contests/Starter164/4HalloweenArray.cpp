https://www.codechef.com/problems/SPC2025Q5

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        long long n,l,r;
        cin>>n>>l>>r;
        vector<long long>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(), arr.end());
        int b=0;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                b=1;
                if(l==0) cout<<"YES\n";
                else cout<<"NO\n";
                break;
            }
        }
        if(b==0){
                if(n>20){
                    cout<<"NO\n";
                }
                else{
                    long long cnt = 1;
                    bool flag=false;
                    for(int i =0;i<n && !flag;i++){
                        for(int j =i+1;j<n && !flag;j++){
                            cnt *= arr[i]^arr[j];
                            if(cnt>r){
                                flag = true;
                                break;
                            }
                        }
                    }
                    if(!flag && cnt>=l && cnt<=r){
                        cout<<"YES\n";
                    }
                    else cout<<"NO\n";
                }
            }
        
	}
}
