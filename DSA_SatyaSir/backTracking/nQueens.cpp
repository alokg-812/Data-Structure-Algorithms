#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &mat, int i, int j) {
    int r = i, c = j;
    
    // Check column
    while (r >= 0) {
        if (mat[r][c] == 'Q') return false;
        r--;
    }

    // Check left diagonal
    r = i, c = j;
    while (r >= 0 && c >= 0) {
        if (mat[r][c] == 'Q') return false;
        r--; c--;
    }

    // Check right diagonal
    r = i, c = j;
    while (r >= 0 && c < mat.size()) {
        if (mat[r][c] == 'Q') return false;
        r--; c++;
    }

    return true;
}

void print(vector<vector<char>> &mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int nQueens(vector<vector<char>> &mat, int i, int n) {
    if (i == n) {
        print(mat);
        return 1;
    }

    int cnt = 0;
    for (int j = 0; j < n; j++) {
        if (isValid(mat, i, j)) {
            mat[i][j] = 'Q';  // Place queen
            cnt += nQueens(mat, i + 1, n);
            mat[i][j] = '.';  // Remove queen (backtrack)
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n, '.'));
    int res = nQueens(mat, 0, n);
    cout << "Total Solutions: " << res << endl;
    return 0;
}