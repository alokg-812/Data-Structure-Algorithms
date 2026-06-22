class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>count(26,0);
        for(char ch:text){
            count[ch-'a']++;
        }
        int maxi=count['b'-'a'];
        maxi=min(maxi,count['a'-'a']);
        maxi=min(maxi,count['l'-'a']/2);
        maxi=min(maxi,count['o'-'a']/2);
        maxi=min(maxi,count['n'-'a']);
        return maxi;

    }
};