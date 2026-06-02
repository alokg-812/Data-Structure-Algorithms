class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int mini = 2e9;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int land_finish = landStartTime[i] + landDuration[i];
                int water_start = max(land_finish, waterStartTime[j]);
                int total_finish1 = water_start + waterDuration[j];
                
                int water_finish = waterStartTime[j] + waterDuration[j];
                int land_start = max(water_finish, landStartTime[i]);
                int total_finish2 = land_start + landDuration[i];

                mini = min(mini, min(total_finish1, total_finish2));
            }
        }
        return mini;
    }
};