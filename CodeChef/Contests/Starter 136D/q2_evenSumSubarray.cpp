#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; // test cases
    cin>>T;
    int count_0 = 0,count_1 = 0;
	while(T--){
        int n,tSum = 0,maxLen = 0;
        cin>>n;
        vector <int> arr(n);
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
            tSum = tSum + arr[j];
        }
        if(tSum % 2 == 0){
            cout<<n<<endl;
            continue;
        }
        
        int l_idx = -1;
        int r_idx = -1;

        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 != 0) {
                l_idx = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] % 2 != 0) {
                r_idx = i;
                break;
            }
        }
        int odd_left_remove = 0;
        if (l_idx != -1) {
            odd_left_remove = n - l_idx - 1;
        }
        int odd_right_remove = 0;
        if (r_idx != -1) {
            odd_right_remove = r_idx;
        }
        int maxLength = max(odd_left_remove, odd_right_remove);
        cout << maxLength << endl;
    }
}