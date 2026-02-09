#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> vec = {4,2,1};
    sort(vec.begin(), vec.end());  //Sort the vector
    cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2];
    return 0;
}
