class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1Dis = abs(z - x);
        int p2Dis = abs(z - y);
        if(p1Dis < p2Dis){
            return 1;
        }
        else if(p2Dis < p1Dis){
            return 2;
        }
        else if(p1Dis == p2Dis){
            return 0;
        }
        return -1;
    }
};