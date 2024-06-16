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
void size(Node* a){
    int size = 0;
    Node* temp = a;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    cout<<size;
}
void display(Node* a){
    Node* temp = a;
    while(temp != NULL){
        cout<<temp->val<<endl;
        temp = temp->next;
    }
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    display(a);
    size(a);
}
