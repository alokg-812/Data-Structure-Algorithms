#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0 ; i< n;i++){
	        cin>>arr[i];
	    }
	   // sort(arr.begin(),arr.end());
	   sort(arr,arr+n);
	    
	    bool flag = true;
	    for(int i = 0 ; i<n;i++){
	        if(arr[i] > i+1){
	            flag = false;
	            break;
	        }
	    }
	    if(flag){
	        cout<<"YES\n";
	    }
	    else cout<<"NO\n";
    }
}