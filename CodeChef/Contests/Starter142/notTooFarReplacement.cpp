#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>arr(n+1);
	    for(int i =0;i<=n;i++){
	       cin>>arr[i];
	    }
	    int lst = arr[n];
	    while(true){
	        bool flag = false;
	        for(int i =0;i<n;i++){
	            if(arr[i]<=2*lst){
	                if(lst<arr[i]){
	                    swap(arr[i],arr[n]);
	                    lst = arr[n];
	                    flag = true;
	                }
	            }
	        }
	        if(!flag) break;
	    }
	    int ans=0;
	    for(int i =0;i<n;i++){
	        ans = ans+arr[i];
	    }
	    cout<<ans<<"\n";
	}

}

