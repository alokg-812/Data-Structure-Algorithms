class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = n;
        bool found = false;

        for(int i = 0;i<n;i++){
            if(words[i] == target){
                found = true;
                
                int directDist = abs(i - startIndex);
                int wrapDist = n - directDist;
                int curr = min(directDist, wrapDist);                
                minDistance = min(minDistance, curr);
            }
        }
        return found ? minDistance : -1;
    }
};