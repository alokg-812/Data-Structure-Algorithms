#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int n1 = 20;
    int n2 = 15;
    cout<<gcd(n1, n2)<<endl;
}
