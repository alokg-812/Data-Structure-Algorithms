class Solution {
public:
    int getNext(int n){
        int tot = 0;
        while(n>0){
            int digit = n%10;
            tot += digit*digit;
            n /=10;
        }
        return tot;
    }
    bool isHappy(int n) {
        int orig= n;
        int dup = getNext(n);
        while(dup != 1 and orig != dup){
            orig= getNext(orig);
            dup = getNext(getNext(dup));
        }
        return dup == 1;
    }
};