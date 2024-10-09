#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int>& qu) {
    int n = qu.size();
    while (n--) {
        int temp = qu.front();
        cout << temp << " ";
        qu.pop();
        qu.push(temp);
    }
    cout << endl;
}

void reversedisplay(queue<int>& qu) {
    stack<int> st;
    int n = qu.size();
	while (n--) {
        int temp = qu.front();
        qu.pop();
        st.push(temp);
    }
    while (!st.empty()) {
        qu.push(st.top());
        st.pop();
    }
    display(qu);
}

int main() {
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.push(60);
    display(qu);
    reversedisplay(qu);
    cout << endl;
    qu.pop();
    display(qu);
    reversedisplay(qu);
    cout << endl;
}
