#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]= {7,1,5,3,6,3};
    int n = 6;
    int mini=arr[0], ans=0;
    for(int i =0;i<n;i++){
        mini = min(mini, arr[i]);
        ans = max(ans, arr[i]-mini);
    }
    cout<<ans<<endl;
}
