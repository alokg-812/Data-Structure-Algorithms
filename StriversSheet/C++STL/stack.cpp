#include<bits/stdc++.h>
using namespace std;
void printstack(stack<int> s1)
{
    stack<int> s2=s1;
    while(!s2.empty())  //Iterate while the stack isn't empty
    {
        cout<<s2.top()<<"\n";
        s2.pop();  //Keep popping the elements
    }
}
int main()
{
    stack<int> s;
    for(int i=1;i<=5;i++)
    s.push(i);  //Push in the value of i int the stack
    
    cout<<"The elements of the stack are:"<<endl;
    printstack(s);
    
    cout<<"The size of the stack: "<<s.size()<<endl;
    cout<<"The top element of the queue: "<<s.top()<<endl;
    cout<<"Pop the top element: "<<endl;
    s.pop();  //Pop the elements
    printstack(s);
}
