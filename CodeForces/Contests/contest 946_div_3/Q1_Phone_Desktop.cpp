#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int z = 0 ; z<t;z++) {
        int x,y;
        cin >> x >> y;
        int count=0;
        if(y%2==0){
        	count = y/2;
    	}
    	else{
    		count = y/2 +1;
		}
		if(y%2==1 && x<=(count*7+4)){
			cout << count << "\n";
		}	
		else if(y%2==0 && x<=count*7){
			cout << count << "\n";
		}
		else{
			if(y%2==1){
				x = x - count*7 - 4;
			}
			else{
				x = x-count*7;
			}
			if(x%15==0){
				count = count+x/15;
			}
			else{
				count = count + x/15+1;
			}
			cout << count << "\n";
		}	
    }    
    return 0;
}

