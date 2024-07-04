#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> arr(n), brr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
        }
        
        vector<int> remA(m, 0), remB(m, 0);
        for (int i = 0; i < n; i++) {
            remA[arr[i] % m]++;
            remB[brr[i] % m]++;
        }        
        long long ways = 0;
        
        for (int i = 0; i < m; i++) {
            int targ = (m - i) % m;
            ways += (long long)remA[i] * remB[targ];
        }
        
        cout << ways << "\n";
    }
}
