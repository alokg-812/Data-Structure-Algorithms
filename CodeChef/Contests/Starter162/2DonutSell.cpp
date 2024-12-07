#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<int>arr(n);
	    vector<int>brr(m);
	    for(int i =0;i<n;i++) cin>>arr[i];
	    for(int i =0;i<m;i++) cin>>brr[i];
	    int cnt=0;
	    unordered_map<int,int>um;
	    for(int i=0;i<n;i++) um[i+1] = arr[i];
	    for(int i =0;i<m;i++){
            int ans = brr[i];
            if (um[ans] > 0) um[ans]--;
            else cnt++; 
        }
        cout<<cnt<<endl;
	}

}
