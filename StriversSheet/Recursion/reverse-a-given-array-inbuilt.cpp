#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse the array using STL reverse function
    void reverseArray(vector<int>& arr) {
        // Use STL reverse to reverse array in-place
        reverse(arr.begin(), arr.end());
    }
};

// Driver code
int main() {
    // Input array
    vector<int> arr = {1, 2, 3, 4, 5};

    // Create Solution object
    Solution obj;

    // Call function to reverse the array
    obj.reverseArray(arr);

    // Output the reversed array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
