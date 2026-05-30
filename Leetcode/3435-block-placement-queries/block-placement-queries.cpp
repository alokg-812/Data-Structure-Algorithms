#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    int tree[240005];
    int n;

    void update(int node, int start, int end, int idx, int val) {
        if(start == end){
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if(idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int queryMax(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 0;
        if(l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return max(queryMax(2 * node, start, mid, l, r), queryMax(2 * node + 1, mid + 1, end, l, r));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obstacles;
        obstacles.insert(0);
        
        // Find the maximum coordinate bound to size our Segment Tree properly
        int max_x = 0;
        for(const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        max_x = max(max_x, 50005); 
        n = max_x;

        // Initialize segment tree positions with 0
        for(int i = 0; i <= 4 * n; i++) tree[i] = 0;
        
        // Treat infinity or upper bound as a virtual obstacle
        obstacles.insert(n);
        update(1, 0, n, n, n);

        vector<bool> results;
        for(const auto& q : queries) {
            if(q[0] == 1) {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);
                
                obstacles.insert(x);
                
                // Update the broken gap into two smaller gaps
                update(1, 0, n, x, x - prev_obs);
                update(1, 0, n, next_obs, next_obs - x);
            } else {
                int x = q[1];
                int sz = q[2];
                
                auto it = obstacles.lower_bound(x);
                int prev_obs = *prev(it);
                
                // Max gap strictly before or ending exactly at the closest left obstacle
                int max_gap = queryMax(1, 0, n, 0, prev_obs);
                
                // Also check the residual space between the last obstacle before x and x itself
                max_gap = max(max_gap, x - prev_obs);
                
                results.push_back(max_gap >= sz);
            }
        }
        return results;
    }
};