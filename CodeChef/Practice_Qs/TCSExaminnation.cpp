https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/EXAMTIME

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<string> ans;

    for (int i = 0; i < t; ++i) {
        int ddsa, dtoc, ddm;
        int sdsa, stoc, sdm;
        cin >> ddsa >> dtoc >> ddm;
        cin >> sdsa >> stoc >> sdm;

        int dragonTotal = ddsa + dtoc + ddm;
        int slothTotal = sdsa + stoc + sdm;

        if (dragonTotal > slothTotal) {
            ans.push_back("Dragon");
        } else if (slothTotal > dragonTotal) {
            ans.push_back("Sloth");
        } else {
            if (ddsa > sdsa) {
                ans.push_back("Dragon");
            } else if (sdsa > ddsa) {
                ans.push_back("Sloth");
            } else {
                if (dtoc > stoc) {
                    ans.push_back("Dragon");
                } else if (stoc > dtoc) {
                    ans.push_back("Sloth");
                } else {
                    ans.push_back("Tie");
                }
            }
        }
    }

    for (const string &result : ans) {
        cout << result << endl;
    }

    return 0;
}
