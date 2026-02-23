#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int>vt;
  vt.push_back(1);
  vt.emplace_back(2);
  for(int i = 0;i<vt.size();i++){
    cout<<vt[i]<<" ";
  }
  cout<<endl;
}