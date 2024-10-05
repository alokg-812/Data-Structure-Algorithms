#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }  
};

class Deque{
    public:
    	Node* head;
    	Node* tail;
    	int size;
    	Deque(){
        	head = tail = NULL;
        	size = 0;
    	}

    void addFront(int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = tail = temp;
        }
        else{
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void addBack(int val){
        Node* temp = new Node(val);
        if(tail == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            temp->next = NULL;
            tail = temp;
        }
        size++;
    }

    void deleteFront(){
        if(head == NULL){
            cout<<"List is empty\n";
        }
        else{
        	Node* temp = head;
            head = head->next;
            head->prev = NULL;
            size--;
            delete(temp);
        }
    }

    void deleteBack(){
        if(tail == NULL){
            cout<<"List is empty\n";
        }
        else if(tail == head){
            head = NULL;
        }
        else{
        	Node* temp = tail;
            tail->prev->next = NULL;
            tail->prev = NULL;
            size--;
            delete(temp);
        }
    }
    
    int front(){
		if(size == 0){
			cout<<"Queue is EMPTY\n";
			return -1;
		}
		return head->val;
	}
	
	int back(){
		if(size == 0){
			cout<<"Queue is EMPTY\n";
			return -1;
		}
		return tail->val;
	}
	
	bool empty(){
		if(size==0) {
			return true;
		}
		else return false;
	}
   
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
};


int main(){
    Deque dq;
    dq.addFront(10);
    dq.addBack(20);
    dq.addBack(30);
    dq.addBack(40);
    dq.display();
    dq.addFront(5);
    dq.addFront(1);
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.deleteBack();
    dq.display();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
}
