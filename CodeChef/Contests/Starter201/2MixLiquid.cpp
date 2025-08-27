// https://www.codechef.com/START201D/problems/MIXINGLIQ

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int syr =a;
        int wat = b/2;
        int used=min(syr, wat);
        int tot = 3*used;
        cout<<tot<<endl;
    }
}