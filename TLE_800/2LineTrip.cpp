#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int pre=0;
        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans, a[i]-pre);
            pre = a[i];
        }
        ans = max(ans, 2*(x-pre));
        cout<<ans<<endl;
    }
}