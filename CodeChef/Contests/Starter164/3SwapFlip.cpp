https://www.codechef.com/problems/SWAPFLIP

#include<bits/stdc++.h>
using namespace std;
string check(int x[],int y[]){
    if((abs(x[1] -y[1]) %2 ==0) && (abs(x[0]-y[0])%2 ==0)) return "YES";
    return "NO";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        int cntA[2] = {0, 0};
        int cntB[2] = {0, 0};
        for (int i=0; i<n; i++){
            cntA[a[i]-'0']++;
            cntB[b[i]-'0']++;
        }
        cout<<check(cntA,cntB)<<endl;
    }
}
