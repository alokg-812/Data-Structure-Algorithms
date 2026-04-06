class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0;
        set<pair<int, int>> ob;
        for(const auto& obs : obstacles){
            ob.insert({obs[0], obs[1]});
        }

        int x = 0, y = 0;
        int max_dist = 0;
        for(int cmd : commands){
            if(cmd == -2){
                dir = (dir+3) %4;
            }
            else if(cmd == -1){
                dir = (dir+1) %4;
            } else{
                for(int i = 0; i<cmd;i++){
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];
                    if(ob.count({nextX, nextY})) {
                        break; 
                    }
                    x = nextX;
                    y = nextY;
                    max_dist = max(max_dist, x*x + y*y);
                }
            }
        }
        return max_dist;
    }
};