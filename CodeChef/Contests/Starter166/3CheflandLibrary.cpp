https://www.codechef.com/START166D/problems/BORROWBOOK
https://www.codechef.com/viewsolution/1117680975

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i =0;i<n;i++) cin>>arr[i];
        unordered_map<int,int>penal;
        for(int i =0;i<n;i++){
            int day = arr[i];
            int pen = i+1;
            penal[day] = max(penal[day], pen);
        }
        int ans = 0;
        for(auto i = penal.begin(); i != penal.end();i++){
            ans+=i->second;
        }
        cout<<ans<<endl;
    }
}
