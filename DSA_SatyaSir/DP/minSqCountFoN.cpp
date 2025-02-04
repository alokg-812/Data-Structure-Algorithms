#include <bits/stdc++.h>
using namespace std;

int miniSquares(vector<int>& dp, int n) {
    if (n == 0) {
        return 0;
    }
    if (dp[n] == -1) {
        int mini = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            mini = min(mini, miniSquares(dp, n - i * i));
        }
        dp[n] = mini + 1;
    }
    return dp[n];
}

int main() {
    int n = 12;
    vector<int> dp(n + 1, -1);
    int result = miniSquares(dp, n);
    cout << "Minimum number of perfect squares for " << n << " is: " << result << endl;
    return 0;
}