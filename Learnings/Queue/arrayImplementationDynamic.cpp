#include<iostream>
#include<vector>
using namespace std;

class Queue{
public:
	int f; // representing front
	int b; // representing back
	vector<int>arr;
	Queue(int val){
		f = 0;
		b = 0;
		vector<int> v(val);
		arr=v;
	}
		
	void push(int val){
		if(b >= arr.size()){
			cout<<"Queue is FULL.\n";
			return;
		}
		else{
			arr[b] = val;
			b++;
		}
	}
	
	void pop(){
		if(arr.size() ==0) {
			cout<<"Queue is EMPTY.\n";
			return;
		}
		f++;
	}
	
	int front(){
		if(arr.size() ==0) {
			cout<<"Queue is EMPTY.\n";
			return -1;
		}
		return arr[f];
	}
	
	int rear(){
		if(arr.size() ==0) {
			cout<<"Queue is EMPTY.\n";
			return -1;
		}
		return arr[b-1];
	}
	
	bool empty(){
		if(arr.size() ==0) {
			return true;
		}
		else return false;
	}
	
	void display(){
		if(arr.size() ==0) {
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
	int n;
	cout<<"Enter the size of the array:";
	cin>>n;
	Queue q(n);
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