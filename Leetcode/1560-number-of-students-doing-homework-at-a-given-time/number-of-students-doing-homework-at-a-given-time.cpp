class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int cnt = 0;
        for(int i = 0;i<startTime.size();i++){
            if(queryTime<=endTime[i] and queryTime>=startTime[i]) cnt++;
        }
        return cnt;
    }
};