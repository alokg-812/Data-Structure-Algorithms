#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string s){
	int n = s.length();
	if(n%2 != 0){
		return false;
	}
	else{
		if (s[0] == ')') return false;
		else{
			stack<char> st;
			for(int i=0;i<n;i++){
				if(s[i] == '(') st.push(s[i]);
				else {
					if(st.size() == 0) return false;
					else st.pop();
				}
			}	
			return true;	
		}		
	}		
}

int main(){
	string s;
	cout<<"Enter the string: ";
	cin>>s;
	cout<<isBalanced(s)<<endl;
}