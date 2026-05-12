class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks){
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int energy = 0;
        int curr = 0;
        for(auto& task : tasks){
            int actual = task[0];
            int minimum = task[1];
            if(curr < minimum){
                int need = minimum-curr;
                energy += need;
                curr+= need;
            }   
            curr-= actual;
        }
        return energy;
    }
};