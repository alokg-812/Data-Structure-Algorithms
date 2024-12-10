https://www.geeksforgeeks.org/problems/juggler-sequence3930/0

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long>arr;
        arr.push_back(n);
        while(n!=1){
            if(n%2 != 0){
                n = n*sqrt(n);
            }
            else{
                n = sqrt(n);
            }
            arr.push_back(n);
        }
        //arr.push_back(1);
        return arr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
