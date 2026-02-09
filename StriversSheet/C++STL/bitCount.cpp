#include <iostream>
#include<bit>
using namespace std;

int main() {
    int x = 12; // Works with signed int as well due to well-defined conversion
    int count = __builtin_popcount(x); 
    cout << "Number of set bits in 12: " << count << endl; // Output: 2

    long long y = 255LL; // Binary: 11111111
    int count_ll = __builtin_popcountll(y);
    cout << "Number of set bits in 255: " << count_ll << endl; // Output: 8

    return 0;
}
