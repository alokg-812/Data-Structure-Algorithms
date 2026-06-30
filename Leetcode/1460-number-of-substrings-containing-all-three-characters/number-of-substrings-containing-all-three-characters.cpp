class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int left = 0;
        int n = s.length();
        int tot= 0;
        for(int right = 0;right<n;right++){
            count[s[right] - 'a']++;
            while(count[0] > 0 and count[1] > 0 and count[2] > 0){
                tot += (n - right);
                count[s[left] - 'a']--;
                left++;
            }
        }

        return tot;
    }
};