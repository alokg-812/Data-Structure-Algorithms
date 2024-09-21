#include<bits/stdc++.h>
using namespace std;

int solve(int val1, int val2, char ch){
    if(ch == '+'){
        return val1 + val2;
    }else if(ch == '-'){
        return val1 - val2;
    }else if(ch == '*'){
        return val1 * val2;
    }else if(ch == '/'){
        return val1 / val2;
    }else return 0;
}
int main(){
	string s = "79+4*8/3-";
	stack<int>val;
	for(int i =0;i<s.size();i++){
		if(s[i] >= 48 && s[i] <= 57){ // If true, it is a digit
            val.push(s[i] - 48);      // Convert char to integer and push
        }
        else{
            // If it's not a digit (it's an operator)
            // work(evaluation)
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = solve(val1,val2,s[i]);
            val.push(ans);
        }   
    }
    // Output the final result
    cout << val.top() << endl;
    // cout<<2+6*4/8-3<<endl;
    cout<<(7+9)*4/8-3<<endl;
    // cout<<7+9*4/8-3<<endl;
}
