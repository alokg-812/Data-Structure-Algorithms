#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(2*n);
	    for(int i=0;i<2*n;i++){
	        cin>>arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    bool flag = true;
	    int cnt=0;
	    for(int i=0;i<2*n;i++){
	        if(arr[i]==arr[i-1]){
	            cnt++;
	            if(cnt>2){
	                flag = false;
	                break;
	            }
	        }
	        else cnt =1;
	        
	    }
	     cout<<(flag?"Yes\n" :"No\n");
	}

}
