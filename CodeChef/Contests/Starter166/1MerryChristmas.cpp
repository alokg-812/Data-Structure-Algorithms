https://www.codechef.com/START166D/problems/MERRYXMAS
https://www.codechef.com/viewsolution/1117650126

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int x;
    cin>>x;
    vector<int>ans = {1,2,4};
    int cnt =0,total = 0;
    for(int i :ans){
        if(total + i <=x){
            total +=i;
            cnt++;
        }
        else break;
    }
    cout<<cnt<<endl;
}
