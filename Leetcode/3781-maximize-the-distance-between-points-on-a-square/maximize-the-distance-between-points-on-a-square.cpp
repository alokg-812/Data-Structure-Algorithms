class Solution {
public:
    int maxDistance(int side_int, vector<vector<int>>& points, int k) {
        long long side = side_int;
        int n = points.size();
        
        struct Point {
            long long pos;
            long long x, y;
            bool operator<(const Point& other) const {
                return pos < other.pos;
            }
        };
        
        vector<Point> pts(n);
        for (int i = 0; i < n; ++i) {
            long long x = points[i][0];
            long long y = points[i][1];
            long long pos = 0;
            
            if (y == 0) pos = x;
            else if (x == side) pos = side + y;
            else if (y == side) pos = 3LL * side - x;
            else pos = 4LL * side - y;
            
            pts[i] = {pos, x, y};
        }
        
        sort(pts.begin(), pts.end());
        
        vector<long long> unrolled_pos(2 * n);
        for (int i = 0; i < n; ++i) {
            unrolled_pos[i] = pts[i].pos;
            unrolled_pos[i + n] = pts[i].pos + 4LL * side;
        }
        
        // 1. Pre-allocate all buffers once to avoid TLE from heap allocations
        vector<int> nxt(2 * n);
        vector<int> curr(2 * n);
        vector<int> power(2 * n);
        vector<int> next_power(2 * n);
        
        // Fixed-size stack arrays since max intervals mathematically cannot exceed 16
        pair<long long, long long> base[8];
        pair<long long, long long> adj[16];
        pair<long long, long long> merged[16];
        
        long long left = 0, right = 2LL * side;
        long long ans = 0;
        
        while (left <= right) {
            long long M = left + (right - left) / 2;
            long long S = 4LL * side;
            
            for (int i = 0; i < n; ++i) {
                long long curr_pos = unrolled_pos[i];
                long long x0 = pts[i].x;
                long long y0 = pts[i].y;
                
                int base_sz = 0;
                long long K;
                
                // Bottom Edge (y = 0)
                K = M - y0;
                if (K <= 0) { base[base_sz++] = {0, side}; }
                else {
                    if (x0 + K <= side) base[base_sz++] = {x0 + K, side};
                    if (x0 - K >= 0) base[base_sz++] = {0, x0 - K};
                }
                    
                // Right Edge (x = side)
                K = M - (side - x0);
                if (K <= 0) { base[base_sz++] = {side, 2LL * side}; }
                else {
                    if (y0 + K <= side) base[base_sz++] = {side + y0 + K, 2LL * side};
                    if (y0 - K >= 0) base[base_sz++] = {side, side + y0 - K};
                }
                    
                // Top Edge (y = side)
                K = M - (side - y0);
                if (K <= 0) { base[base_sz++] = {2LL * side, 3LL * side}; }
                else {
                    if (x0 + K <= side) base[base_sz++] = {2LL * side, 3LL * side - (x0 + K)};
                    if (x0 - K >= 0) base[base_sz++] = {3LL * side - (x0 - K), 3LL * side};
                }
                    
                // Left Edge (x = 0)
                K = M - x0;
                if (K <= 0) { base[base_sz++] = {3LL * side, 4LL * side}; }
                else {
                    if (y0 + K <= side) base[base_sz++] = {3LL * side, 4LL * side - (y0 + K)};
                    if (y0 - K >= 0) base[base_sz++] = {4LL * side - (y0 - K), 4LL * side};
                }
                
                int adj_sz = 0;
                for (int j = 0; j < base_sz; ++j) {
                    if (base[j].first > base[j].second) continue;
                    long long L = base[j].first, R = base[j].second;
                    
                    if (R < curr_pos) {
                        adj[adj_sz++] = {L + S, R + S};
                    } else if (L <= curr_pos && curr_pos <= R) {
                        adj[adj_sz++] = {curr_pos, R};
                        adj[adj_sz++] = {L + S, R + S};
                    } else {
                        adj[adj_sz++] = {L, R};
                        adj[adj_sz++] = {L + S, R + S};
                    }
                }
                
                sort(adj, adj + adj_sz);
                
                int merged_sz = 0;
                for (int j = 0; j < adj_sz; ++j) {
                    if (merged_sz > 0 && adj[j].first <= merged[merged_sz - 1].second) {
                        if (adj[j].second > merged[merged_sz - 1].second) {
                            merged[merged_sz - 1].second = adj[j].second;
                        }
                    } else {
                        merged[merged_sz++] = adj[j];
                    }
                }
                
                int best_j = 2 * n;
                for (int j = 0; j < merged_sz; ++j) {
                    long long L = merged[j].first, R = merged[j].second;
                    auto it = lower_bound(unrolled_pos.begin() + i + 1, unrolled_pos.begin() + i + n + 1, L);
                    if (it != unrolled_pos.begin() + i + n + 1 && *it <= R) {
                        best_j = it - unrolled_pos.begin();
                        break;
                    }
                }
                
                nxt[i] = best_j;
                nxt[i + n] = min(best_j + n, 2 * n);
            }
            
            // 2. Binary lifting loop (reusing pre-allocated state arrays)
            for (int i = 0; i < 2 * n; ++i) {
                power[i] = nxt[i];
                curr[i] = i;
            }
            
            int steps = k - 1;
            while (steps > 0) {
                if (steps % 2 == 1) {
                    for (int i = 0; i < 2 * n; ++i) {
                        curr[i] = (curr[i] < 2 * n) ? power[curr[i]] : 2 * n;
                    }
                }
                steps /= 2;
                if (steps > 0) {
                    for (int i = 0; i < 2 * n; ++i) {
                        next_power[i] = (power[i] < 2 * n) ? power[power[i]] : 2 * n;
                    }
                    for (int i = 0; i < 2 * n; ++i) {
                        power[i] = next_power[i];
                    }
                }
            }
            
            bool possible = false;
            for (int i = 0; i < n; ++i) {
                int end = curr[i];
                if (end <= i + n) {
                    long long x1 = pts[end % n].x, y1 = pts[end % n].y;
                    long long x2 = pts[i].x, y2 = pts[i].y;
                    if (abs(x1 - x2) + abs(y1 - y2) >= M) {
                        possible = true;
                        break;
                    }
                }
            }
            
            if (possible) {
                ans = M;
                left = M + 1;
            } else {
                right = M - 1;
            }
        }
        
        return ans;
    }
};