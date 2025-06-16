#include<bits/stdc++.h>
using namespace std;
vector<int> median(vector<int>arr){
    int n = arr.size();
    priority_queue<int>b1;
    // priority_queue<int, vector<int>, greater<int>>b2;
    priority_queue<int> b2; // min heap
    vector<int>ans(n);
    ans[0] = arr[0];
    b1.push(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>b1.top()){
            b2.push(-arr[i]);
        }
        else{
            b1.push(arr[i]);
        }
        int size_diff = b1.size()-b2.size();
        if(size_diff>1){
            b2.push(-b1.top());
            b1.pop();
        }
        else if(size_diff<0){
            b1.push(-b2.top());
            b2.pop();
        }
        if(size_diff == 1){
            ans[i] = b1.top();
        }
        else{
            ans[i] = (b1.top() + (-b2.top()))/2;
        }
    }
    return ans;
}
int main(){
    vector<int>arr = {6, 10 , 2, 24, 12, -1, 20, 4};
    vector<int>res = median(arr);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}