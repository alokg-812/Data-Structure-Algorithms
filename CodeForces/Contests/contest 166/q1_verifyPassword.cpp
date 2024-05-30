#include<bits/stdc++.h>
using namespace std;

bool is_goodPass(const string& str) {
    string digits, letters;
    bool letter_found = false;
    for (char c : str) {
        if (isdigit(c)) {
            if (letter_found) return false;
            digits += c;
        } else if (islower(c)) {
            letter_found = true;
            letters += c;
        } else {
            return false;
        }
    }

    for (size_t i = 1; i < digits.size(); i++) {
        if (digits[i] < digits[i - 1]) {
            return false;
        }
    }

    for (size_t i = 1; i < letters.size(); i++) {
        if (letters[i] < letters[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        if (is_goodPass(str)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
