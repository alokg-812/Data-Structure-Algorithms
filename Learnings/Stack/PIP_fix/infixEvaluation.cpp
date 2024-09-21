#include<iostream>
#include<stack>
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

int solve(int val1, char ch, int val2){
    if(ch == '+'){
        return val1 + val2;
    }
    else if(ch == '-'){
        return val1 - val2;
    }
    else if(ch == '*'){
        return val1 * val2;
    }
    else if(ch == '/'){
        return val1 / val2;
    }
    return 0;
}

int main(){
    string s = "2+6*4/8-3";  // Input expression without spaces
    stack<int> val;          // Stack to store values
    stack<char> op;          // Stack to store operators

    for(int i = 0; i < s.size(); i++){
        // Step 1: Check if s[i] is a digit
        if(s[i] >= 48 && s[i] <= 57){ // If true, it is a digit
            val.push(s[i] - 48);      // Convert char to integer and push
        }
        else{
            // If it's not a digit (it's an operator)
            if(op.empty()){
                op.push(s[i]);  // If operator stack is empty, just push operator
            }
            else if(prio(op.top()) < prio(s[i])){
                op.push(s[i]);  // Push current operator if it has higher precedence
            }
            else{
                // While current operator precedence is less than or equal to top of stack
                while(!op.empty() && prio(op.top()) >= prio(s[i])){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, ch, val2);
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
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, ch, val2);
        val.push(ans);    
    }
    
    // Output the final result
    cout << val.top() << endl;
}
