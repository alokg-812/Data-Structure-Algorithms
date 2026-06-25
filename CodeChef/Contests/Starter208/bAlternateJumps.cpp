//  https://www.codechef.com/START208D/problems/ALJMP

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	while(n--){
	    int a;
	    cin>>a;
	    if(a%2==0){
	        cout<<a/2<<endl;
	    }
	    else{
	        cout<<(a+1)/2<<endl;
	    }
	    
	}

}
