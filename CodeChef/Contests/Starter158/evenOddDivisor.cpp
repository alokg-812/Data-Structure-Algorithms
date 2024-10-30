#include <bits/stdc++.h>
using namespace std;

int func(int n) {
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            arr.push_back(i);
        }
    }

    int odd = 0, ev = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) ev++;
        else odd++;
    }
    if (ev > odd) return 1;
    else if (odd > ev) return -1;
    else return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << func(n) << endl;
    }
}
