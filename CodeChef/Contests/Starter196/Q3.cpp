#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vector<int>arr(n),brr(n);
        for(int i = 0; i< n; i++){
            cin>>arr[i];
        }
        for(int i = 0; i< n; i++){
            cin>>brr[i];
        }
        set<int>poss ={0};
        for(int i = 0; i<n;i++){
            poss.insert(brr[i]);
        }

        long long maxi = LLONG_MIN;
        for (int l: poss){
            long long sum = 0;
            for(int i = 0;i<n; i++){
                if(brr[i]<=l && arr[i]> 0){
                    sum+= arr[i];
                }
            }
            long long sat = sum-l;
            maxi = max(maxi, sat);
        }

        cout<<maxi<<endl;
    }

    return 0;
}