class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 1) return encodedText;
        int n = rows;
        int m = encodedText.length()/rows;
        vector<vector<char>> arr(n, vector<char>(m));
        int idx=0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = encodedText[idx];
                idx++;
            }
        }
        string ans = "";
        for(int startCol = 0;startCol<m;startCol++){
            int r = 0, c = startCol;
            while(r<n and c<m){
                ans += arr[r][c];
                r++;
                c++;
            }
        }        
        while(!ans.empty() and ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};