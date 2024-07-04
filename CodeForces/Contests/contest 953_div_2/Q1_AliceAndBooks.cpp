#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int maxi = *max_element(arr.begin(), arr.end());
        int sec_maxi = *max_element(arr.begin(), arr.end() - 1);
        if (arr[n - 1] == maxi) {
            maxi += sec_maxi;
        } else {
            maxi += arr[n - 1];
        }
        cout << maxi << endl;
    }
}
