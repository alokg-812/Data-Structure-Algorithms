https://www.codechef.com/START174C/problems/DELDIF
https://www.codechef.com/viewsolution/1134479233

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    int tot = n, c0 = cnt[0];
    for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it){
        if(it->first!= 0){
            int pair = it->second/2;
            tot -= pair;
            c0 += pair;
        }
    }
    while(c0>=2){
        int pair = c0 / 2;
        tot -= pair;
        c0 -= pair;
    }
    cout<<tot<<endl;
}

int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
