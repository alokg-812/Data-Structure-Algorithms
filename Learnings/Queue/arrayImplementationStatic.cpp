#include<iostream>
using namespace std;

class Queue{
public:
	int f; // representing front
	int b; // representing back
	int arr[5];
	int size;
	Queue(){
		f = 0;
		b = 0;
		size = b-f;
	}
		
	void push(int val){
		if(b >= 5){
			cout<<"Queue is FULL.\n";
			return;
		}
		else{
			arr[b] = val;
			b++;
			size++;
		}
	}
	
	void pop(){
		if(size ==0) {
			cout<<"Queue is EMPTY.\n";
			return;
		}
		f++;
	}
	
	int front(){
		if(size ==0) {
			cout<<"Queue is EMPTY.\n";
			return -1;
		}
		return arr[f];
	}
	
	int rear(){
		if(size ==0) {
			cout<<"Queue is EMPTY.\n";
			return -1;
		}
		return arr[b-1];
	}
	
	bool empty(){
		if(size ==0) {
			return true;
		}
		else return false;
	}
	
	void display(){
		if(size ==0) {
			cout<<"Queue is EMPTY.\n";
			return;
		}
		else{
			for(int i = f;i<b;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	}
};


int main(){
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
return 0;
}