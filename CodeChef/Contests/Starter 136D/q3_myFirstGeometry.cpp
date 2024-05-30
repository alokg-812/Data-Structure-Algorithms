#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum = sum + (s[i] - '0'); 
        }

        if (sum == 1) {
            cout << "11\n";
        } else if (sum == 2) {
            if ((s[0] == '1' && s[1] == '1') || (s[0] == '0' && s[1] == '0')) {
                cout << "21\n";
            } else {
                cout << "121\n";
            }
        } else if (sum == 3) {
            cout << "231\n";
        } else if (sum == 4) {
            cout << "441\n";
        }
    }

    return 0;
}
