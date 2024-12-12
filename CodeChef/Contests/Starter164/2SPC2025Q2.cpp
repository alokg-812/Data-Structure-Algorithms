https://www.codechef.com/problems/SPC2025Q2

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int k,p,n;
	    cin>>n>>k>>p;
	    vector<int>arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr.begin(), arr.end());
	    int tall = arr[n-1];
	    int sum = 0;
	    for(int i=0;i<n-1;i++){
	        sum +=arr[i];
	    }
	    int vedh = k+tall;
	    int varh = p+sum;
	    if(vedh>varh) cout<<"Ved\n";
	    else if(vedh<varh) cout<<"Varun\n";
	    else cout<<"Equal\n";
	}

}
