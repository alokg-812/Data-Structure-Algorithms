class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;
        double hPos = (hour*30.0) + (minutes*0.5);
        double mPos = minutes*6.0;
        double diff = abs(hPos-mPos);

        return min(diff, 360.0 - diff);
    }
};