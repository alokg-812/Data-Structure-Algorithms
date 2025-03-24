#include <iostream>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s){
    stack<char>st;
    for(char ch:s){
        if(st.empty() || ch!=st.top()){
            st.push(ch);
        }
        else st.pop();
    }
    string res = "";
    while(st.size()>0){
        res = st.top() + res;
        st.pop();
    }
    return res;
}
// string removeDuplicates(string s){
//     unordered_map<char, int> um;
//     um['a'] = 0;
//     um['b'] = 0;
//     um['c'] = 0;
//     um['d'] = 0;
//     um['e'] = 0;
//     um['f'] = 0;
//     um['g'] = 0;
//     um['h'] = 0;
//     um['i'] = 0;
//     um['j'] = 0;
//     um['k'] = 0;
//     um['l'] = 0;
//     um['m'] = 0;
//     um['n'] = 0;
//     um['o'] = 0;
//     um['p'] = 0;
//     um['q'] = 0;
//     um['r'] = 0;
//     um['s'] = 0;
//     um['t'] = 0;
//     um['u'] = 0;
//     um['v'] = 0;
//     um['w'] = 0;
//     um['x'] = 0;
//     um['y'] = 0;
//     um['z'] = 0;
//     string result = "";
//     for (char ch : s) {
//         if (um[ch] == 0) {
//             result += ch;
//             um[ch] = 1;
//         }
//     }
//     return result;
// }



int main() {
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;
    return 0;
}
