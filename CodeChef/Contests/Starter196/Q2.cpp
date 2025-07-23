#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int x = 0;
        while(true){
            int neww = c+x;
            bool flag = false;
            for(int i = 0;i<n;i++){
                if(arr[i] == neww){
                    flag = false;
                    break;
                }
            }
            bool flag2 = false;
            for(int i =0;i<n;i++){
                if(neww >arr[i]){
                    flag2 = true;
                    break;
                }
            }
            if(!flag and flag2){
                cout<<x<<endl;
                break;
            }
            x++;
        }
    }
}