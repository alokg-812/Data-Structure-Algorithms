class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        int i = 0;
        while(i<n){
            int cnt = 0;
            char curr = word[i];
            while(i<n and word[i] == curr and cnt <9){
                cnt++;
                i++;
            }
            comp += to_string(cnt) + curr;
        }
        return comp;
    }
};
