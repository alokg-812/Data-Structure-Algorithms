#include<iostream>
#include<queue>
using namespace std;

void display(queue<int>& qu){
	int n = qu.size();
	for(int i = 0 ;i<n;i++){
		int temp = qu.front();
		cout<<temp<<" ";
		qu.pop();
		if(i%2 !=0){
			qu.push(temp);
		}
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
    display(qu);
    qu.pop();
    display(qu);
}