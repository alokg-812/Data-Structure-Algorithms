https://www.geeksforgeeks.org/problems/absolute-distinct-count5118/0

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function template for C++

class Solution {
  public:
    int distinctCount(vector<int>& arr) {
        // code
        unordered_set<int> us;
        for(int i = 0;i<arr.size(); i++){
            if(arr[i]>0){
                us.insert(arr[i]);
            }
            // us.insert(arr[i]);
        }
        return us.size();
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.distinctCount(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
