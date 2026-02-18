class Solution {
public:
    //code by alok
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long dup = x;
        long long rev = 0;
        while(x>0){
            long long ld = x%10;
            rev = (rev*10) + ld;
            x=x/10;
        }
        if(dup==rev){
            return true;
        }
        else{
            return false;
        }
    }
};