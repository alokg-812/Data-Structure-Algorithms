class Solution {
public:
    int countCommas(int n){
        if (n < 1000) return 0;

        long long total = 0;
        string s = to_string(n);
        int len = s.length();

        for (int digits = 4; digits <= len; ++digits) {
            long long count;
            if (digits == len) {
                count = n - (long long)pow(10, len - 1) + 1;
            } else {
                count = 9LL * (long long)pow(10, digits - 1);
            }

            int com = (digits - 1) / 3;
            total += count * com;
        }

        return total;
    }
};