#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <string> v;
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int count = 0;
    int loc = arr[n];
    for(int i = n-1 ; i > 0 ; i--){
        if(arr[i] == 1){
            count++;
            loc = arr[i];
            v.push_back("A");
        }
        for(int j = i ; j > 0 ; j--){
        if(arr[j] == 0){
            count++;
            loc = arr[j];
            v.push_back("B");
        }
    }
    }
    cout<<v<<endl;
}