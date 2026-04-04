#include<bits/stdc++.h>
using namespace std;

int armstrong(int n){
    vector<int>arr;
    while(n>0){
        int temp = n%10;
        arr.push_back(temp);
        n = n/10;
    }
    int cnt = arr.size();
    int sum=0;
    for(int i =0;i<cnt;i++){
        sum += pow(arr[i],cnt);
    }
    return sum;
}

int main(){
    int n = 153;
    cout<<armstrong(n)<<endl;
}
