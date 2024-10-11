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
void deleteAtHead(Node* temp){
    Node* head = temp;
    Node* trav = temp;
    head = head->next;
    delete(trav);
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    display(a);
    deleteAtHead(a);
    display(a);
}