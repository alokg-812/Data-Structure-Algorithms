#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverse(string& str) {
    int n = str.length();
    string reversedStr = str;
	for (int i = 0; i < n / 2; i++) {
        swap(reversedStr[i], reversedStr[n - i - 1]);
    }
    return reversedStr;
}

string duplicateChars(string s){
	int n=s.size();
	stack <char>st;
	st.push(s[0]);
	for(int i =1;i<n;i++){
		if(s[i] != st.top()) st.push(s[i]);
	}
	string t="";
	while(st.size()>0){
		t += st.top();
		st.pop();
	}
	return reverse(t);
}

int main(){
	string s;
	cout<<"Enter the string: ";
	cin>>s;
	cout<<duplicateChars(s);
}