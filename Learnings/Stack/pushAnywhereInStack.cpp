#include<bits/stdc++.h>
#include<stack>
using namespace std;
void display(stack <int> st){
	while(st.size()>0){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
void pushAtTop(stack<int>&st, int val){
	st.push(val);
	return;
}
void pushAtBottom(stack<int>&st, int val){
	stack<int> temp;
	while(st.size()>0){
		temp.push(st.top());
		st.pop();
	}
	st.push(val);
	while(temp.size()>0){
		st.push(temp.top());
		temp.pop();
	}
	return;
}
void pushAtIndex(stack<int>&st,int i, int val){
	
	if(i<0 || i>st.size()){
        cout<<"Index out of bounds"<<endl;
        return;
    }
    	stack<int> temp;
		while(st.size() > i){
			temp.push(st.top());
			st.pop();
		}
		st.push(val);
		while(temp.size()>0){
			st.push(temp.top());
			temp.pop();
		}
		return;	
}

int main(){
    stack<int> st;
    st.push(8);
    st.push(18);
    st.push(28);
    st.push(38);
    st.push(48);
    st.push(58);
    display(st);
    pushAtTop(st, 65);
    display(st);
    pushAtBottom(st, 887);
    display(st);
    pushAtIndex(st,3, 7);
    display(st);
}