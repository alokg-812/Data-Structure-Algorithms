class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if(colors[0] != colors[n-1]){
            return n-1;
        }
        int i = 0,j=n-1;
        while(colors[i]==colors[j]) j--;
        int dist = abs(i-j);
        j = n-1;
        while(colors[i]==colors[j]) i++;
        dist = max(dist, abs(i-j));
        return dist;
    }
};