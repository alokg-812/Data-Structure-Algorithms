class Solution {
public:
    int minOperations(string s) {
        int flips0 = 0, flips1 = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] != (i%2 == 0 ? '0' : '1'))
                flips0++;
            if(s[i] != (i%2 == 0 ? '1' : '0'))
                flips1++;
        }
        return min(flips0, flips1);
    }
};