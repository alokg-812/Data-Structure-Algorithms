// https://www.codechef.com/problems/CAKEMAKE

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int cnt = 0;
	int a,b;
	cin>>a>>b;
	for(int i = 0;i<a;i++){
	    for(int j =0;j<b;j++){
	        if(i!=j) cnt++;
	    }
	}
	cout<<cnt<<endl;

}
