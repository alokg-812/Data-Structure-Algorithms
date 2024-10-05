#include<bits/stdc++.h>
#include<iostream>
#include<vector>
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

class Queue{
public:
	Node* head; // representing front
	Node* tail; // representing back
	int len;
	
	Queue(){
		head = tail = NULL;
		len = 0;
	}

	void push(int data){
		Node* temp = new Node(data);
		if(len ==0){
			head = tail = temp;
		}
		else{
			tail->next = temp;
			tail = temp;			
		}
		len++;
	}
	
	void pop(){
		if(len == 0){
			cout<<"Queue is EMPTY\n";
			return;
		}
		Node* temp = head;
		head = head->next;
		len--;
		delete(temp);
	}
	
	int front(){
		if(len == 0){
			cout<<"Queue is EMPTY\n";
			return -1;
		}
		return head->val;
	}
	
	int rear(){
		if(len == 0){
			cout<<"Queue is EMPTY\n";
			return -1;
		}
		return tail->val;
	}
	
	bool empty(){
		if(len==0) {
			return true;
		}
		else return false;
	}
	
	void display(){
		if(len ==0) {
			cout<<"Queue is EMPTY.\n";
			return;
		}
		else{
			Node* temp = head;
            while (temp != NULL) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
		}
	}
};


int main(){
	int n;
	Queue q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.display();
	q.push(50);
	q.push(60);
	q.display();
	q.pop();
	q.display();
	q.pop();
	q.display();
	return 0;
}