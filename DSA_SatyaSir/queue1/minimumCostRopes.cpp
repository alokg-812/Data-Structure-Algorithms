//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        int ans = 0;
        while(pq.size()> 1){
            int min1 = pq.top();
            pq.pop();
            int min2 = pq.top();
            pq.pop();
            int cost = min1 +min2;
            ans += cost;
            pq.push(cost);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends