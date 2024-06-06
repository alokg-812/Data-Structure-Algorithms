#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; // t is the test cases;
	cin>>t;
	while(t--){
	    int n; // number of input in each test cases
	    cin>>n;
	    int x[n],y[n];
	    for(int k = 0 ; k < n ; k++){
	        cin>>x[k]>>y[k];       
	    }
        int ans = 0 ;
        for(int i = 0 ; i < n; i++){
            for(int j = i +1 ; j < n ; j++){
                int str = ((x[i] * y[j]) + (y[i] * x[j]));
                if(str > ans){
                    ans = str;
                }       
            }
        }
        cout<<ans<<"\n";
	   // for(int i = 0 ; i < n-1 ; i++){
	   //     if(((x[i] * y[i+1]) +(x[i+1] * y[i]) ) > ans){
	   //         ans = ((x[i] * y[i+1]) +(x[i+1] * y[i]) );
	   //     }
	   // }
	}
}
