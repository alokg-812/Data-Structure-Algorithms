class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(n, 0);
        
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                heights[col] = matrix[row][col] == 1 ? heights[col] + 1 : 0;
            }
            
            vector<int> sortedHeights = heights;
            sort(sortedHeights.begin(), sortedHeights.end(), greater<int>());
            
            for (int i = 0; i < n; ++i) {
                if (sortedHeights[i] == 0) break; 
                maxArea = max(maxArea, sortedHeights[i] * (i + 1));
            }
        }
        
        return maxArea;
    }
};