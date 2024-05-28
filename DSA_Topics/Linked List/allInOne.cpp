#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head= new_node;
}

void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtKth(Node* &head, int idx, int val){
    if(idx == 0) {
        insertAtHead(head, val);
        return;
    }
    Node* new_node = new Node(val);
    Node* temp = head;
    int current_index = 0;
    while(current_index != idx-1){
        temp = temp->next;
        current_index++;
    }
    //after this loop work is completed, temp is pointing to node at position (idx-1)
    new_node->next = temp->next;
    temp->next = new_node;
}

void updateAtKth(Node* &head, int k, int val){
    Node* temp = head;
    int current_position = 0;
    while(current_position != k){
        temp = temp->next;
        current_position ++;
    }
    //at the end of the loop, temp will be pointing towards kth node'
    temp->val = val;
}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    // temp->next = NULL;
    free(temp);
    // cout<<temp<<"    "<<temp->next<<endl;
}

void deleteAtTail(Node* &head){
    Node* secondLast = head;
    while(secondLast->next->next != NULL){
        secondLast = secondLast->next;
    }
    Node* temp = secondLast->next;
    secondLast->next = NULL;
    free(temp);
    // cout<<temp<<endl;  //giving some random address
}

void deleteAtKth(Node* &head, int k){
    if(k == 0){
        return deleteAtHead(head);
    }
    else{
        Node* temp = head;
    int count = 0;
    while(count<k-1){
        temp = temp->next;
        count++;
    }
    //after the loop, temp is one index previous which has to be deletd
    Node* pre = temp->next;
    temp->next = pre->next;
    free(pre);
    }
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 2); 
    display(head);              //2->NULL
    insertAtHead(head,8);
    display(head);              //8->2->NULL
    insertAtTail(head,3);
    display(head);              //8->2->3->NULL
    insertAtKth(head,2,9);
    display(head);              //8->2->9->3->NULL
    insertAtKth(head,0,11);
    display(head);
    updateAtKth(head,2,5);
    display(head);
     
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtKth(head,2);
    display(head);
} 
