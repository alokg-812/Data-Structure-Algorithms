class Fancy {
private:
    long long add = 0;
    long long mul = 1;
    const int MOD = 1e9 + 7;
    vector<long long> seq;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {
    }
    
    void append(int val) {
        long long v = ((val - add) % MOD + MOD) % MOD; 
        v = (v * modInverse(mul)) % MOD;
        seq.push_back(v);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * mul + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */