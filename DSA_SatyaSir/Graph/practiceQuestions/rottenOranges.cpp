#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> time(m, vector<int>(n, -1));

    // Push all initially rotten oranges and mark their time as 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
                time[i][j] = 0;
            }
        }
    }

    int r[] = {-1, 1, 0, 0};
    int c[] = {0, 0, -1, 1};
    int maxTime = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + r[i];
            int ny = y + c[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                time[nx][ny] = time[x][y] + 1;
                maxTime = max(maxTime, time[nx][ny]);
                q.push({nx, ny});
            }
        }
    }

    // Check if any fresh orange is left
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1; // Impossible to rot all oranges
            }
        }
    }

    return maxTime;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 1, 2, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 2, 1, 1, 1},
        {1, 1, 1, 1, 1},
    };

    int time = orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << time << endl;
}