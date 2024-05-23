#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; // test cases
    cin>>T;
	for(int i = 0 ; i < T ; i++){
        int x,y;
        cin>>x>>y;
        int x_ = x%3;
        int y_ = y%3;
        cout<<min(x_,y_)<<"\n";
    }
}