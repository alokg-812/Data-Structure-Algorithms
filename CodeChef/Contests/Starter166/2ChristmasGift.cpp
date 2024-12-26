https://www.codechef.com/START166D/problems/WRAPGIFTS
https://www.codechef.com/viewsolution/1117657918

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int h, b, l;
	    cin>>h>>l>>b;
	    cout<<1000/(2*(l*b+b*h+h*l))<<endl;
	}
}
