class Solution {
private:
    struct Ride {
        int start;
        int duration;
        int finish;
    };

    int solveOneWay(const vector<Ride>& firstRides, const vector<Ride>& secondRides) {
        int n = firstRides.size();
        int m = secondRides.size();
        int min_total = 2e9;
        vector<int> preMin(m);
        preMin[0] = secondRides[0].duration;
        for(int j = 1;j<m;j++){
            preMin[j] = min(preMin[j-1], secondRides[j].duration);
        }
        int j = 0;
        int min_first_finish = 2e9;

        for(int i = 0;i<n;i++){
            while(j < m && secondRides[j].start <= firstRides[i].finish){
                j++;
            }
            if(j > 0){
                min_total = min(min_total, firstRides[i].finish + preMin[j-1]);
            }
            if(j < m){
            }
        }
        int best_first_idx = 0;
        for(int i = 1;i<n;i++){
            if(firstRides[i].finish < firstRides[best_first_idx].finish) best_first_idx = i;
        }
        for(int k = 0;k<m;k++){
            int start_time = max(firstRides[best_first_idx].finish, secondRides[k].start);
            min_total = min(min_total, start_time + secondRides[k].duration);
        }

        int best_second_idx = 0;
        for(int k = 1;k<m;k++){
            if(secondRides[k].start + secondRides[k].duration < secondRides[best_second_idx].start + secondRides[best_second_idx].duration){
                best_second_idx = k;
            }
        }
        for(int i = 0;i<n;i++){
            int start_time = max(firstRides[i].finish, secondRides[best_second_idx].start);
            min_total = min(min_total, start_time + secondRides[best_second_idx].duration);
        }

        return min_total;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<Ride> land(n);
        for(int i = 0;i<n;i++){
            land[i] = {landStartTime[i], landDuration[i], landStartTime[i] + landDuration[i]};
        }

        vector<Ride> water(m);
        for(int j = 0;j<m;j++){
            water[j] = {waterStartTime[j], waterDuration[j], waterStartTime[j] + waterDuration[j]};
        }
        sort(land.begin(), land.end(), [](const Ride& a, const Ride& b){
            return a.finish < b.finish;
        });

        sort(water.begin(), water.end(), [](const Ride& a, const Ride& b){
            return a.start < b.start;
        });
        int ans1 = solveOneWay(land, water);        
        sort(water.begin(), water.end(), [](const Ride& a, const Ride& b){
            return a.finish < b.finish;
        });
        sort(land.begin(), land.end(), [](const Ride& a, const Ride& b){
            return a.start < b.start;
        });
        
        int ans2 = solveOneWay(water, land);

        return min(ans1, ans2);
    }
};