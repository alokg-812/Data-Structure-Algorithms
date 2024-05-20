#include<bits/stdc++.h>
using namespace std;
// int min(int n1,int n2){
//     if(n1>=n2){
//         return n1;
//     }
//     else return n2;
// }
int main() {
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        if((p1+p2+p3)%2 == 1){
            cout<<-1<<endl;
        }// else if(p1 == 0){
        //     cout<<min(p2,p3)<<endl;
        // } else if(p2 == 0){
        //     cout<<min(p1,p3)<<endl;
        // } else if(p3 == 0){
        //     cout<<min(p1,p2)<<endl;
        // } 
        else if((p1%2 == 0) and (p2%2 == 0) and (p3%2 == 0)){
            cout<<(p1+p2+p3)/2<<endl;
        } else if(p3>=(p1+p2)){
            cout<<p1+p2<<endl;
        } else if ((p1 == 1 and p2 == 1 and p3 == 0) or (p1 == 0 and p2 == 1 and p3 == 1) or (p1 == 1 and p2 == 0 and p3 == 1)){
            cout<<1<<endl;
        } else {
            cout<<((p1+p2+p3)/2)<<endl;
        }
    }
}
