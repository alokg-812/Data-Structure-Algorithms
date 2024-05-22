#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while (T--) {
        int N;
        cin >> N;
        int cows = N / 4;
        int leftLegs = N % 4;
        int hen = 0;
        if (leftLegs != 0) {
            hen = 1;
        }
        int anm = cows + hen;
        cout << anm << endl;
    }
}