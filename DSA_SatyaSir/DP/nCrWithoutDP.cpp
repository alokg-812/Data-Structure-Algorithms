#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n==1) return 1;
    else return n*fact(n-1);
}

int nCr(int n, int r){
    if(r==0 or r==n) return 1;
    if(r==1) return n;
    if(r>n) return 0;
    int nmr = fact(n);
    int dmr = fact(r)*fact(n-r);
    return nmr/dmr;
}

int main() {
    int n, r;
    cout << "Enter values of n and r: ";
    cin >> n >> r;
    cout << "nCr(" << n << ", " << r << ") = " << nCr(n, r) << endl;
    return 0;
}