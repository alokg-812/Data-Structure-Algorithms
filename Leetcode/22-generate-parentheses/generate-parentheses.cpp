class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr = "";
        backtrack(res, curr, 0, 0, n);
        return res;
    }

private:
    void backtrack(vector<string>& res, string& curr, int open, int close, int maxi){
        if(curr.length() == maxi*2){
            res.push_back(curr);
            return;
        }
        if(open<maxi){
            curr.push_back('(');
            backtrack(res, curr, open+1, close,maxi);
            curr.pop_back();
        }
        if(close <open) {
            curr.push_back(')');
            backtrack(res, curr, open, close+1, maxi);
            curr.pop_back();
        }
    }
};