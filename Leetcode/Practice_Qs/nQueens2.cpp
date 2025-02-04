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

int nQueens(vector<vector<char>> &mat, int i, int n) {
    if (i == n) {
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

int totalNQueens(int n) {
    vector<vector<char>> mat(n, vector<char>(n, '.'));
    return nQueens(mat, 0, n);
}

int main() {
    int n;
    cin >> n;
    int res = totalNQueens(n);
    cout << "Total Solutions: " << res << endl;
    return 0;
}