#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 496;
    vector<int>arr;
    for(int i = 1;i<n;i++){
        if(n%i==0){
            cout<<i<<" ";
            arr.push_back(i);
        }
    }
    cout<<endl;
    int sum=0;
    for(int i =0;i<arr.size();i++){
        sum+=arr[i];
    }
    if(sum==n){
        cout<<n<<" is a perfect number.";
    }else{
        cout<<n<<" is not a perfect number.";
    }
    cout<<endl;
    return 0;
}
