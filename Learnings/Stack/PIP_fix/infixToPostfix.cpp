#include<bits/stdc++.h>
using namespace std;

int prio(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0; // Return 0 for any other character
}

string work(string val1, char ch, string val2){
	string s = "";
	s+=val1;
	s+=val2;
    s.push_back(ch);
	return s;
}

int main(){
	string s = "2+6*4/8-3";
	stack<char>op;
	stack<string>val;
	for(int i =0;i<s.size();i++){
		if(s[i] >= 48 && s[i] <= 57){ // If true, it is a digit
            val.push(to_string(s[i] - 48));      // Convert char to integer and push
        }
        else{
            // If it's not a digit (it's an operator)
            if(op.size()==0 || (prio(op.top()) < prio(s[i]))){
                op.push(s[i]);  // If operator stack is empty, just push operator
            }
            else{
                // While current operator precedence is less than or equal to top of stack
                while(!op.empty() && prio(op.top()) >= prio(s[i])){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = work(val1, ch, val2);
                    val.push(ans);
                }
                op.push(s[i]); // Push the current operator
            }
        }   
    }
    
    // Process remaining operators in the stack
    while(!op.empty()){
        char ch = op.top();
        op.pop();
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = work(val1, ch, val2);;
        val.push(ans);   
    }
    
    // Output the final result
    cout << val.top() << endl;
}
