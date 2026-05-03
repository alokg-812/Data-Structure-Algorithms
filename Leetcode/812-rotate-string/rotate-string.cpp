class Solution {
public:
    bool rotateString(string s,string goal){
        if(s.size()!=goal.size()) return false;
        string temp=s+s;
        int pos=temp.find(goal);
        if(pos!=-1) return true;
        return false;
    }
};