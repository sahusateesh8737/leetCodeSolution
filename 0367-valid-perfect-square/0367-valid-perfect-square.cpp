class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <0)return false;
        if(num == 0 || num == 1){
            return true;
        }
        long high = num;
        long low = 1;
        while(low <= high){
            long mid = low + (high-low) /2;
            long  squ = mid * mid;
            if(squ == num){
                return true;
            }
            else if(squ < num){
                low = mid +1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};