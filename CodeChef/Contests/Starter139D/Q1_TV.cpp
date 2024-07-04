#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int x;
    cin>>x;
    if(x%2 == 0){
        cout<<x/2;
        return 0;
    }
    else cout<<(x/2)+1;
    return 0;
}
