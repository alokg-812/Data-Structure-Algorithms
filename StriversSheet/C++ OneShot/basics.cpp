#include <iostream>    // For input/output
#include <string>      // For using strings
using namespace std;

// Function Example (outside main)
void greetUser(string name) {
    cout << "Hello, " << name << "! Welcome to learning C++!" << endl;
}

int addNumbers(int x, int y) {
    return x + y;  // Returns sum of two numbers
}

int main() {

    // 1. Output Statement
    cout << "Welcome to Basic C++ Program!" << endl;

    // 2. Variables and Data Types
    int age = 20;
    float height = 5.9;
    char grade = 'A';
    bool isStudent = true;
    string name = "Alok";

    // Displaying variable values
    cout << "Name: " << name << ", Age: " << age << ", Height: " << height << endl;

    // 3. Input from user
    cout << "Enter your name: ";
    cin >> name;   // Takes one word input
    greetUser(name);  // Calling function

    // 4. If-Else Condition
    if (age >= 18) {
        cout << "You are an adult." << endl;
    } else {
        cout << "You are a minor." << endl;
    }

    // 5. For Loop Example
    cout << "Counting from 1 to 5: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;


    // 7. While Loop Example
    int count = 3;
    while (count > 0) {
        cout << "Countdown: " << count << endl;
        count--;
    }

    // 8. Function to add numbers
    int sum = addNumbers(4, 5);
    cout << "Sum of 4 and 5 using function: " << sum << endl;

    // 9. Pointer Example
    int num = 50;
    int* ptr = &num;  // Pointer storing address of num
    cout << "Value of num using pointer: " << *ptr << endl;  // Dereferencing pointer

    return 0;
}
