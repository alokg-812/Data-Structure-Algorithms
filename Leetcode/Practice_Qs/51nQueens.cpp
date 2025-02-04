https://leetcode.com/problems/n-queens/description/
https://leetcode.com/problems/n-queens/submissions/1531383549/

class Solution {
public:
    bool isValid(vector<string> &mat, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (mat[i][col] == 'Q') return false;
        }

        // Check left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (mat[i][j] == 'Q') return false;
        }

        // Check right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (mat[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string> &mat, vector<vector<string>> &soln) {
        if (row == n) {
            soln.push_back(mat);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(mat, row, col, n)) {
                mat[row][col] = 'Q';  // Place queen
                solve(row + 1, n, mat, soln);
                mat[row][col] = '.';  // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> soln;
        vector<string> mat(n, string(n, '.'));
        solve(0, n, mat, soln);
        return soln;
    }
};
