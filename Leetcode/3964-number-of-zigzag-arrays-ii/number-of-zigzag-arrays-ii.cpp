class Solution {
public:
    long long mod = 1e9 + 7;

    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int size) {
        vector<vector<long long>> C(size, vector<long long>(size, 0));
        for(int i = 0;i<size;i++){
            for(int k = 0;k<size;k++){
                if(A[i][k] == 0) continue;
                for(int j = 0;j<size;j++){
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> A, int p, int size) {
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1;

        while (p > 0) {
            if (p & 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int size = 2 * m;

        vector<vector<long long>> T(size, vector<long long>(size, 0));
        for (int u = 0; u < m; ++u) {
            for (int v = u + 1; v < m; ++v) {
                T[u][m + v] = 1;
            }
            for (int v = 0; v < u; ++v) {
                T[m + u][v] = 1;
            }
        }

        T = power(T, n - 1, size);
        long long total_count = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                total_count = (total_count + T[i][j]) % mod;
            }
        }

        return total_count;
    }
};