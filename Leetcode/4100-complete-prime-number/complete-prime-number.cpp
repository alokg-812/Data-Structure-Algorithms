class Solution{
public:
    bool isPrime(long long n){
        if(n<= 1) return false;
        if(n<= 3) return true;
        if(n%2 == 0 or n%3 == 0) return false;
        
        for(long long i = 5; i*i<=n;i+=6){
            if(n%i ==0 or n%(i+2)== 0) return false;
        }
        return true;
    }

    bool completePrime(int num){
        if(num<=1) return false;
        
        string s = to_string(num);
        int len = s.length();
        
        for(int i = 1; i<=len;i++){
            long long val = stoll(s.substr(0, i));
            if(!isPrime(val)) return false;
        }        
        for(int i = 1; i<=len;i++){
            long long val = stoll(s.substr(len - i));
            if(!isPrime(val)) return false;
        }
        
        return true;
    }
};