#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declare a multiset of integers
    multiset<int> s;

    // Insert elements 1 to 10
    for (int i = 1; i <= 10; i++) {
        s.insert(i);
    }

    // Insert a duplicate element
    s.insert(5);

    // Display elements in the multiset (ordered automatically)
    cout << "Elements present in the multiset: ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Search for a specific element (2 in this case)
    int n = 2;
    if (s.find(2) != s.end())
        cout << n << " is present in multiset" << endl;

    // Erase the first element
    s.erase(s.begin());

    // Display elements after deletion
    cout << "Elements after deleting the first element: ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Display the size of the multiset
    cout << "The size of the multiset is: " << s.size() << endl;

    // Check if the multiset is empty
    if (!s.empty())
        cout << "The multiset is not empty" << endl;
    else
        cout << "The multiset is empty" << endl;

    // Clear all elements
    s.clear();

    // Display size after clearing
    cout << "Size of the multiset after clearing: " << s.size();
}
