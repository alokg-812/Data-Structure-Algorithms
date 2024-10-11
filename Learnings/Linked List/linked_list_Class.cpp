#include<bits/stdc++.h>
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

class LinkedList{
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    
    //to insert at tail,
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if (size == 0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }


    //to display the linked list,
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"\n";
    }
};

int main(){
    LinkedList ll;
    ll.display();
    ll.insertAtTail(10);
    ll.display();
    ll.insertAtTail(25);
    ll.display();
    ll.insertAtTail(78);
    ll.display();
}