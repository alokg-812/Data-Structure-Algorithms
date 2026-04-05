class Solution {
public:
    bool judgeCircle(string moves) {
        int x_steps=0, y_steps=0;
        for(int i = 0;i<moves.size();i++){
            char move = moves[i];
            if(move == 'U') y_steps++;
            else if(move == 'D') y_steps--;
            else if(move == 'R') x_steps++;
            else if(move == 'L') x_steps--;
        }
        if((x_steps==0) and (y_steps==0)) return true;
        return false;        
    }
};