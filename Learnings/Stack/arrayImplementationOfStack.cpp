#include<iostream>
using namespace std;
class Stack{ //user defined data structure
public:
	int arr[6];
	int idx;
	Stack(){
		idx = -1;
	}
	
	void push(int val){
		if(idx== (sizeof(arr)/sizeof(arr[0])) -1){
			cout<<"Stack OverFlow\n";
			return;
		}
		idx++;
		arr[idx] = val;
	}
	
	void pop(){
		if(idx<=-1){
			cout<<"Stack UnderFlow\n";
			return;
		}
		idx--;
	}
	
	int top(){
		if(idx ==-1){
			cout<<"Stack is empty\n";
			return -1;
		}
		return arr[idx];
	}
	
	void size(){
		cout<<"Current Size of stack is: " <<idx+1<<endl;
	}
};
int main(){
	Stack st;
	st.pop();
	st.top();
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	st.push(23);
	cout<<st.top()<<endl;
//	st.display();
	st.pop();
	st.size();
//	st.display();
}

