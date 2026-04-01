class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });        
        vector<int> stack; 
        
        for(int curr_idx : indices) {
            if (directions[curr_idx] == 'R') {
                stack.push_back(curr_idx);
            } else {
                bool survived = true;
                
                while (!stack.empty() && directions[stack.back()] == 'R') {
                    int top_idx = stack.back();
                    
                    if (healths[top_idx] < healths[curr_idx]) {
                        stack.pop_back();
                        healths[curr_idx] -= 1;
                    } else if (healths[top_idx] > healths[curr_idx]) {
                        healths[top_idx] -= 1;
                        survived = false;
                        break;
                    } else {
                        stack.pop_back();
                        survived = false;
                        break;
                    }
                }
                if (survived) {
                    stack.push_back(curr_idx);
                }
            }
        }
        
        sort(stack.begin(), stack.end());
        vector<int> result;
        for (int idx : stack) {
            result.push_back(healths[idx]);
        }
        
        return result;
    }
};