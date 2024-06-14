#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >>t;
    while (t--) {
        int x, y;
        cin >>x >>y;
        int upar_ka = 10 * (y -x);
        int neche = 100 -y;
        int ans = (upar_ka + neche - 1) / neche;
        cout << ans<<"\n";
    }
}
