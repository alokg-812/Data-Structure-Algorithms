#include<bits/stdc++.h>
using namespace std;

int main() {
    // Declare an unordered_multiset of integers
    unordered_multiset s;

    // Insert elements from 1 to 10 into the unordered_multiset
    for (int i = 1; i <= 10; i++) {
        s.insert(i);
    }

    // Insert an additional 5 to demonstrate duplicate storage
    s.insert(5);

    // Display all elements of the unordered_multiset
    cout << "Elements present in the unordered multiset: ";
    for (auto it = s.begin(); it != s.end(); it++) { // Iterate over each element
        cout << *it << " "; // Dereference iterator to get the value
    }
    cout << endl;

    int n = 2;
    // Check if element '2' is present using find()
    if (s.find(2) != s.end())
        cout << n << " is present in unordered multiset" << endl;

    // Erase the first element using iterator
    s.erase(s.begin());
    cout << "Elements after deleting the first element: ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Display the size of the unordered_multiset
    cout << "The size of the unordered multiset is: " << s.size() << endl;

    // Check if the unordered_multiset is empty
    if (s.empty() == false)
        cout << "The unordered multiset is not empty " << endl;
    else
        cout << "The unordered multiset is empty" << endl;

    // Clear all elements from the unordered_multiset
    s.clear();
    cout << "Size of the unordered multiset after clearing all the elements: " << s.size();
}
