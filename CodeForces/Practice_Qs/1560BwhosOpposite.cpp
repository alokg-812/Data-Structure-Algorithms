#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int c) {
    int diff = abs(a-b);
    if(diff %2!=0) return -1;
    int n = diff*2;
    if(a>n || b>n || c>n) return -1;
    int opp = (c+n/2);
    if(opp>n) opp -=n;
    return opp;
}

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<check(a,b,c)<<endl;
}