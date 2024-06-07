#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0 ; i < n ; ++i) {
            cin >> arr[i];
        }
        vector <int> maxi;
        for(int i = 0 ; i < n-1 ; i ++){
            maxi.push_back(max(arr[i],arr[i + 1]));
        }
        sort(maxi.begin(),maxi.end());
        cout<<maxi[0]-1<<"\n";
    }
}
