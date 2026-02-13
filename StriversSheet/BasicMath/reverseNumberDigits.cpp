#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        int revNum = 0;
        while (n > 0) {
            int lastDigit = n % 10;
            revNum = revNum * 10 + lastDigit;
            n = n / 10;
        }
        return revNum;
    }
};

int main() {
    Solution obj;
    int num = 12345;
    cout << obj.reverseNumber(num) << endl;  // Output: 54321
    return 0;
}
