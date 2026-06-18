class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(30 * hour - 11.0 * minutes / 2);
        if(ans > 180.0) ans = 360.0 - ans;
        return ans;
    }
};