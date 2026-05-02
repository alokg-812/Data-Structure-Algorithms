class Solution {
public:
    bool isGood(int num){
        bool flag=false;
        while(num){
            int d = num%10;
            if(d == 3 or d==4 or d==7) return false;
            if(d==2 or d==5 or d==6 or d==9) flag=true;
            num/=10;
        }
        return flag;
    }
    int rotatedDigits(int n){
        int count=0;
        for(int i = 1;i<=n;i++) {
            if(isGood(i)) count++;
        }
        return count;
    }
};