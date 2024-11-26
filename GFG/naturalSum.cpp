https://www.geeksforgeeks.org/problems/stuti-and-her-problem5846/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
	public:
   	int check(int n, int i){
        if(n==1) return 1;
        if(i>n) return -1;
        if (i*(i-1) == 2*n) return i-1;
        return check(n,i+1);
    }
    int find(int n){
        return check(n,1);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.find(n);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends
