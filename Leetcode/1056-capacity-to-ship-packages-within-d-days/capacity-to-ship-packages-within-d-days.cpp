class Solution {
public:
    bool canShip(const vector<int>& weights, int days, int capacity){
        int days_needed = 1;
        int current_load = 0;
        
        for(int weight : weights){
            if(current_load+weight > capacity){
                days_needed++;
                current_load = weight;
                if(days_needed>days) return false;
            }
            else current_load += weight;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days){
        int low = INT_MIN;
        int high = 0;
        for(int i = 0;i<weights.size();i++){
            low = max(low, weights[i]);
            high+=weights[i];
        }
        int ans = high;
        
        while(low <= high){
            int mid = low + (high-low) /2;
            if(canShip(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }
        
        return ans;
    }
};