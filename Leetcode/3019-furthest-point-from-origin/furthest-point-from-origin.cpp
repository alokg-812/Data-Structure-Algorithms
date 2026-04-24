class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL=0, cntR=0, cntB=0;
        for(char c: moves){
            if(c=='R') cntR++;
            else if(c=='L') cntL++;
            else cntB++;
        }
        return abs(cntL-cntR)+cntB;
    }
};