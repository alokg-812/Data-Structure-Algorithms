#include<bits/stdc++.h>
using namespace std;

int main(){
  pair<int, pair<int, int>> pairOf3 = {1,{2,3}};
  cout<<pairOf3.first<<endl;
  cout<<pairOf3.second.first<<endl;
  cout<<pairOf3.second.second<<endl;

  pair<int, int> arr[]={{1,0}, {2,9}, {3,8}, {4,7}, {5,6}};
  cout<<arr[1].first; //based on the array indexing and then first or second
}