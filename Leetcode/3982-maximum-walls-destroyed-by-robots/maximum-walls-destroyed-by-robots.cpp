class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        map<int, vector<int>> pos_to_dists;
        for (int i = 0; i < robots.size(); i++) {
            pos_to_dists[robots[i]].push_back(distance[i]);
        }        
        vector<int> U;
        vector<vector<pair<int, int>>> choices;
        for (auto& [p, dists] : pos_to_dists) {
            U.push_back(p);
            sort(dists.rbegin(), dists.rend());
            vector<pair<int, int>> current_choices;
            if (dists.size() == 1) {
                current_choices.push_back({dists[0], 0});
                current_choices.push_back({0, dists[0]});
            } else {
                current_choices.push_back({dists[0], dists[1]});
                if (dists[0] != dists[1]) {
                    current_choices.push_back({dists[1], dists[0]});
                }
            }
            choices.push_back(current_choices);
        }
        set<int> unique_walls(walls.begin(), walls.end());
        int guaranteed = 0;
        vector<vector<int>> W(U.size() + 1); 
        for (int w : unique_walls) {
            if (pos_to_dists.count(w)) {
                guaranteed++;
                continue;
            }
            
            auto it = lower_bound(U.begin(), U.end(), w);
            if (it == U.begin()) {
                W[0].push_back(w);
            } else if (it == U.end()) {
                W[U.size()].push_back(w);
            } else {
                int idx = std::distance(U.begin(), it);
                W[idx].push_back(w);
            }
        }
        
        int M = U.size();
        vector<vector<int>> dp(M);
        for (int i = 0; i < M; i++) {
            dp[i].resize(choices[i].size(), 0);
        }
        for (int c = 0; c < choices[0].size(); c++) {
            int l_cov = choices[0][c].first;
            int r_limit = U[0] - l_cov;
            
            auto it = lower_bound(W[0].begin(), W[0].end(), r_limit);
            dp[0][c] = std::distance(it, W[0].end());
        }
        for (int i = 1; i < M; i++) {
            for (int c = 0; c < choices[i].size(); c++) {
                int l_cov = choices[i][c].first;
                int p_curr = U[i];
                int best = 0;
                
                for (int pc = 0; pc < choices[i-1].size(); pc++) {
                    int r_cov = choices[i-1][pc].second;
                    int p_prev = U[i-1];
                    
                    int r_limit = p_prev + r_cov;
                    int l_limit = p_curr - l_cov;
                    
                    int destroyed = 0;
                    if (r_limit >= l_limit) {
                        destroyed = W[i].size();
                    } else {
                        auto it_r = upper_bound(W[i].begin(), W[i].end(), r_limit);
                        int right_count = std::distance(W[i].begin(), it_r);
                        
                        auto it_l = lower_bound(W[i].begin(), W[i].end(), l_limit);
                        int left_count = std::distance(it_l, W[i].end());
                        
                        destroyed = right_count + left_count;
                    }
                    
                    best = max(best, dp[i-1][pc] + destroyed);
                }
                dp[i][c] = best;
            }
        }
        int ans = 0;
        for (int c = 0; c < choices[M-1].size(); c++) {
            int r_cov = choices[M-1][c].second;
            int r_limit = U[M-1] + r_cov;
            
            auto it = upper_bound(W[M].begin(), W[M].end(), r_limit);
            int count = std::distance(W[M].begin(), it);
            ans = max(ans, dp[M-1][c] + count);
        }
        
        return ans + guaranteed;
    }
};