#include <bits/stdc++.h>
using namespace std;

int check(int n, int m, int k){
    int tot = n*m;
    int cnt = 0;
    for(int i = 1; i<m; i++){
        int left = n*i;
        int right = n*(m-i);
        if(left>=k) cnt = max(cnt, right);
        if(right>=k) cnt = max(cnt, left);
    }
    for(int i =1;i<n;i++){
        int top = i*m;
        int bottom = (n-i)*m;
        if(top>=k) cnt = max(cnt, bottom);
        if(bottom>=k) cnt = max(cnt, top);

    }
    if(tot >= k) cnt = max(cnt, tot-k);
    return cnt;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n, m, k;
	    cin>>n>>m>>k;
	    cout<<check(n,m,k)<<endl;
	}
}
