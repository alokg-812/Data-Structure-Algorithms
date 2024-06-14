#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int ans = 2;
        int maxSum = 0;
        for (int x = 2; x <= n; x++) {
            int currSum = 0;
            for (int k = 1; k * x <= n; k++) {
                currSum += k * x;
            }
            
            if (currSum > maxSum) {
                maxSum = currSum   ;
                ans = x;
            }
        }
        cout<<ans<<"\n";
    }
}