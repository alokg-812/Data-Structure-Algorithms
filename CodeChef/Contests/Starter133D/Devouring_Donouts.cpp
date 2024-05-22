#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        int N = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + N);
        int sum_aage = 0 ; 
        int sum_pche = 0 ; 
        if (n % 2 == 0) {
            int half = n / 2;
            for (int l = 0; l < half; l++) {
                sum_aage += arr[l];
            }
            for (int l = half; l < n; l++) {
                sum_pche += arr[l];
            }
        }
        else{
            int half = (n-1)/2;
        for(int l = 0 ; l < half ; l++){
            sum_aage += arr[l];
        }
        for(int l = half ; l < n ; l++){
            sum_pche += arr[l];
        }
        }
        cout<<(sum_pche - sum_aage)<<endl;
    }
}
