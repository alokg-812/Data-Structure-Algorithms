class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1){
            return '0';
        }
        long long len = (1LL << (n-1)) - 1;        
        long long mid = len+1;
        
        if(k == mid){
            return '1';
        }        
        if(k < mid){
            return findKthBit(n-1, k);
        }
        long long pos = (len << 1) + 2-k;
        
        char bit = findKthBit(n-1, pos);        
        return (bit == '0') ? '1' : '0';
    }
};