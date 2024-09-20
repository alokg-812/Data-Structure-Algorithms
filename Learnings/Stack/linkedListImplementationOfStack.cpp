#include<iostream>
using namespace std;
class Node{
public:
	int val;
	Node* next;
	Node(int val){
		this->val = val;
		this->next = NULL;
	}
};

class Stack{
public:
	Node* head;
	int size;
	Stack(){
		size = 0;
		head = NULL;
	}
	void push(int val){
		Node* temp = new Node(val);
		temp->next = head;
		head = temp;
		size++;		
	}
	void pop(){
		if(head == NULL){
			cout<<"Empty Stack\n";
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;		
	}
	int top(){
		if(head == NULL){
			cout<<"Empty Stack\n";
			return -1;
		}
		return head->val;
	}
	void print(Node* temp){
		if(temp == NULL) return;
		print(temp->next);
		cout<<temp->val<<" ";
	}                  
	
	void display(){
		Node* temp = head;
		print(temp);
		cout<<endl;
	}
};

int main(){
	Stack st;
	st.push(10);
	st.push(23);
	cout<<st.size<<endl;
	cout<<st.top()<<endl;
	st.display();
}