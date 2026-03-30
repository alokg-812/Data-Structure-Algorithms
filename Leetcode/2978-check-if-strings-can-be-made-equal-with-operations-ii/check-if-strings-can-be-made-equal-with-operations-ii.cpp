class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.length() != s2.length()){
            return false;
        }
        vector<int> eve1(26, 0), eve2(26, 0);
        vector<int> od1(26, 0), od2(26, 0);
        int n = s1.length();
        for(int i = 0;i<n;i++){
            if(i%2 == 0){
                eve1[s1[i] - 'a']++;
                eve2[s2[i] - 'a']++;
            } else{
                od1[s1[i] - 'a']++;
                od2[s2[i] - 'a']++;
            }
        }
        for(int i = 0;i<26;i++){
            if(eve1[i] != eve2[i] or od1[i] != od2[i]){
                return false;
            }
        }
        return true;
    }
};