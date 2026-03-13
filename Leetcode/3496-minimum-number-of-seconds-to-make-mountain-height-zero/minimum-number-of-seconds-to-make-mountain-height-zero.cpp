#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = 1LL * *min_element(workerTimes.begin(), workerTimes.end()) 
                        * mountainHeight * 1LL * (mountainHeight+1)/2 +1;
        
        while(left<right){
            long long mid = left+(right-left)/2;
            
            if(canFinish(mountainHeight, workerTimes, mid)){
                right = mid;
            } 
            else{
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool canFinish(long long height, const vector<int>& times, long long maxTime) {
        long long total = 0;
        for(int t : times){
            long long lo = 0;
            long long hi = 2e5; 
            while(lo < hi){
                long long mid = lo + (hi-lo+1) / 2;
                long long cost = t* mid* (mid+1) / 2;
                if(cost <= maxTime){
                    lo = mid;
                }
                else{
                    hi = mid - 1;
                }
            }
            total += lo;
            if(total >= height){
                return true;
            }
        }
        return total >= height;
    }
};