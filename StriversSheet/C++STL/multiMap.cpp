#include<bits/stdc++.h>

using namespace std;

int main() {
  multimap < int, int > mp;
  for (int i = 1; i <= 5; i++) {  //Iterate in the map till 5
    mp.insert({i , i * 10});  //Insert elements from i to i*10
  }
  mp.insert({4,40}); 

  cout << "Elements present in the multimap: " << endl;  //Print the elements in the map
  cout << "Key\tElement" << endl;  //Print the keys in the map
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it -> first << "\t" << it -> second << endl;  //Print it.first and second from the map
  }

  int n = 2;
  if (mp.find(2) != mp.end())
    cout << n << " is present in multimap" << endl;  //If element in found

  mp.erase(mp.begin());
  cout << "Elements after deleting the first element: " << endl;
  cout << "Key\tElement" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it -> first << "\t" << it -> second << endl;
  }

  cout << "The size of the multimap is: " << mp.size() << endl;

  if (mp.empty() == false)
    cout << "The multimap is not empty " << endl;  //If map is not empty
  else
    cout << "The multimap is empty" << endl;  //If map is empty
  mp.clear();
  cout << "Size of the multimap after clearing all the elements: " << mp.size();  //Print the size of the map
}
