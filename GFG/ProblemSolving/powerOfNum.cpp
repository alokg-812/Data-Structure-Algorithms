https://www.geeksforgeeks.org/problems/power-of-numbers-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pow(int a, int b){
        if(b==0) return 1;
        return a*pow(a,b-1);
    }
    int reverseExponentiation(int n) {
        // code here
        if(n<10) return pow(n,n);
        int num = n%10;
        num = num*10+n/10;
        return pow(n,num);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T; // test cases

    while (T--) {
        int n;
        cin >> n; // input N

        Solution ob;
        // power of the number to its reverse
        int ans = ob.reverseExponentiation(n);
        cout << ans << endl;
    }

    return 0;
}

// } Driver Code Ends
