class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        if(m==0) return 0;
        int n = mat[0].size();
        if(n==0) return 0;
        
        vector<int> rowOnes(m, 0);
        vector<int> colOnes(n, 0);
        
        for(int i = 0; i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]){
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }
        
        int count = 0;
        for(int i = 0;i<m;i++){
            if(rowOnes[i]==1){
                for(int j = 0;j<n;j++){
                    if(mat[i][j] == 1 and colOnes[j] == 1){
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};