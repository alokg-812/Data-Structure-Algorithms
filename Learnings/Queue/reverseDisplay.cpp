#include<iostream>
#include<queue>
using namespace std;

void reversedisplay(queue<int>& qu){
    if(qu.empty()){
        return;
    }    
    int temp = qu.front();
    qu.pop();
    reversedisplay(qu); // Recursive calling with the reduced queue
    cout << temp << " ";
    qu.push(temp); // Adding the element back after printing
}

int main(){
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.push(60);
    
    cout << "Front: " << qu.front() << " Rear: " << qu.back() << " Size: " << qu.size() << endl;
    
    reversedisplay(qu);
    cout << endl;
    
    qu.pop();
    cout << "Front: " << qu.front() << " Rear: " << qu.back() << " Size: " << qu.size() << endl;
    
    reversedisplay(qu);
    cout << endl;
    
    return 0;
}
