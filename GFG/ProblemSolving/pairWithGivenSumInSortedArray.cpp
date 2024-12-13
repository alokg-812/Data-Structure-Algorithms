https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPair(int k, vector<int> &arr) {
        // Complete the function
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int p1=0;
        int p2 = n-1;
        int cnt = 0;
        while(p1<p2){
            int sum =arr[p1]+arr[p2];
            if(sum == k){
                cnt++;
                p1++;
                p2--;
            }
            else if(sum>k) p2--;
            else p1++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        vector<int> arr;
        int k;
        cin >> k;
        string input;
        getline(cin, input);
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.countPair(k, arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
