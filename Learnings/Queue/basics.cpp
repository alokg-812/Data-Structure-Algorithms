#include<iostream>
#include<queue>
using namespace std;

void display(queue<int>& qu){
	int n = qu.size();
	while(n--){
		int temp = qu.front();
		cout<<temp<<" ";
		qu.pop();
		qu.push(temp);
	}
	cout<<endl;
}

int main(){
    queue<int>qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.push(60);
    cout<<"Front: "<<qu.front()<<" Rear: "<<qu.back()<<" Size: "<<qu.size()<<endl;
    display(qu);
    qu.pop();
    cout<<"Front: "<<qu.front()<<" Rear: "<<qu.back()<<" Size: "<<qu.size()<<endl;
    display(qu);
}