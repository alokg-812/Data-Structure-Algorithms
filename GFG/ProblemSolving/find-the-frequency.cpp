https://www.geeksforgeeks.org/problems/find-the-frequency/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

/*Function to find frequency of x
 * x : element whose frequency is to be found
 * arr : input vector
 */
class Solution {
  public:
    int findFrequency(vector<int> arr, int k) {
        // Your code here
        unordered_map<int, int> um;
        for(int i =0;i<arr.size();i++){
            um[arr[i]]++;
        }
        for(auto it : um){
            if(it.first == k){
                return it.second;
            }
        }
        return 0;
        }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.findFrequency(arr, x) << endl;
    }

    return 0;
}
// } Driver Code Ends
