class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, cnt = 0;
        for(string str: events){
            if(str == "W") cnt++;
            else if((str =="WD") or (str=="NB")) score++;
            else score += stoi(str);
            
            if(cnt ==10) break;
        }
        vector<int>ans;
        ans.push_back(score);
        ans.push_back(cnt);
        return ans;         
    }
};