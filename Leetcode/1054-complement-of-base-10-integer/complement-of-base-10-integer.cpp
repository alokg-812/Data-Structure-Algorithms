class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        
        int high = 31- __builtin_clz(n);
        unsigned int mask = (1U << (high+1)) - 1;
        return n^mask;
    }
};