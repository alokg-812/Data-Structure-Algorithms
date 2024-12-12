https://www.codechef.com/problems/CONSPERM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            cout << "-1\n";
        } else {
            vector<int> res(n);
            int odd = 1, even = n - 1;

            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    res[i] = odd;
                    odd += 2;
                } else {
                    res[i] = even;
                    even -= 2;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
}
