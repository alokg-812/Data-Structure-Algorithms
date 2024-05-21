#include <bits/stdc++.h>
using namespace std;

vector<string> decodeStrings(int t, const vector<pair<int, string>>& testCases) {
    vector<string> results;
    for (const auto& testCase : testCases) {
        int n = testCase.first;
        string b = testCase.second;
        set<char> charSet(b.begin(), b.end());
        string r(charSet.begin(), charSet.end());
        map<char, char> mapping;
        int len = r.size();
        for (int i = 0; i < len; ++i) {
            mapping[r[i]] = r[len - i - 1];
        }
        string s;
        s.reserve(n);
        for (char ch : b) {
            s.push_back(mapping[ch]);
        }

        results.push_back(s);
    }
    
    return results;
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, string>> testCases(t);

    for (int i = 0; i < t; ++i) {
        int n;
        string b;
        cin >> n >> b;
        testCases[i] = {n, b};
    }

    vector<string> decodedStrings = decodeStrings(t, testCases);

    for (const string& s : decodedStrings) {
        cout << s << endl;
    }

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	// your code goes here
// 	long long t;
// 	cin>>t;
//     long long x = 0;
// 	for(int j = 0 ; j < t ; j++){
// 	    long long i;
// 	    cin>>i;
        
//     }
// }