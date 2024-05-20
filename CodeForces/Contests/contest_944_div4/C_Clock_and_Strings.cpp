#include <bits/stdc++.h>
using namespace std;
bool segments_intersect(int a, int b, int c, int d) {
    int start_ab = min(a, b);
    int end_ab = max(a, b);
    int start_cd = min(c, d);
    int end_cd = max(c, d);
    bool ab_splits_cd = (start_ab < start_cd && end_ab > start_cd && end_ab < end_cd) ||
                        (start_ab > start_cd && start_ab < end_cd && end_ab > end_cd);
    bool cd_splits_ab = (start_cd < start_ab && end_cd > start_ab && end_cd < end_ab) ||
                        (start_cd > start_ab && start_cd < end_ab && end_cd > end_ab);

    return ab_splits_cd || cd_splits_ab;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (segments_intersect(a, b, c, d)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
