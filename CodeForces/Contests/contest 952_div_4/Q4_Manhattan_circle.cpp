#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >>t;
    while (t--) {
        int n,m;
        cin >>n>>m;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int row_min = n, row_max = -1;
        int col_min = m, col_max = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    row_min = min(row_min, i);
                    row_max = max(row_max, i);
                    col_min = min(col_min, j);
                    col_max = max(col_max, j);
                }
            }
        }
        int row_cen = (row_min + row_max) / 2 + 1;
        int col_cen = (col_min + col_max) / 2 + 1;
        cout << row_cen << " " << col_cen << endl;
    }

}
