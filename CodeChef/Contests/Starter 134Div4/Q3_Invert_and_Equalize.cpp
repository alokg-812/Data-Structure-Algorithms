#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; // test cases
    cin>>T;
    
	for(int i = 0 ; i < T ; i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count_0 = 0,count_1 = 0;
        for(int k = 0 ; k<n;k++){
            if(s[k] == '1'){
                while(k<n and s[k] == '1'){
                    k++;
                }
                count_1++;
                k--;
            }
        }
        for(int k = 0 ; k<n;k++){
            if(s[k] == '0'){
                while(k<n and s[k] == '0'){
                    k++;
                }
                count_0++;
                k--;
            }
        }cout<<min(count_0,count_1)<<"\n";
        
    }
}