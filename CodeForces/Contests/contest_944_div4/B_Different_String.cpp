#include <bits/stdc++.h>
using namespace std;
void sort_r(string &s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}
void rev_r(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
}
int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        string s;
        cin >> s;
        if (s.length() == 1) {
            cout << "NO" << endl;
        } else {
            string sorted_s = s;
            sort_r(sorted_s);
            bool isSame = true;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != sorted_s[i]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) {
                rev_r(sorted_s);
                isSame = true;
                for (int i = 0; i < s.length(); i++) {
                    if (s[i] != sorted_s[i]) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                    cout << sorted_s << endl;
                }
            } else {
                cout << "YES" << endl;
                cout << sorted_s << endl;
            }
        }
    }
    return 0;
}