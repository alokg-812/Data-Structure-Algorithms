#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int n = tokens.size();
    for(int i = 0;i<n;i++){
        string token = tokens[i];
        if (token == "+" || token == "-" || token == "*" || token == "/"){
            int b = st.top(); 
            st.pop();
            int a = st.top(); 
            st.pop();
            if (token == "+") st.push(a + b);
            if (token == "-") st.push(a - b);
            if (token == "*") st.push(a * b);
            if (token == "/") st.push(a / b);
        }else{
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main(){
    string tokens[] = {"2","1","+","3","*"};
    vector<string> v(tokens, tokens + sizeof(tokens) / sizeof(tokens[0]));
    cout << evalRPN(v) << endl;
}