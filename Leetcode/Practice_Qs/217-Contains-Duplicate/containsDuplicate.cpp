#include <iostream>
#include <unordered_set>
using namespace std;


bool containsDuplicate(vector<int>& nums) {
    unordered_set<int>us;
    for(int num : nums){
        us.insert(num);
    }
    if(nums.size() == us.size()) return false;
    return true;        
}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << (containsDuplicate(nums) ? "true" : "false") << endl; // Output: true
    return 0;
}