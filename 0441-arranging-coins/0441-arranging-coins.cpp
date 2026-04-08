class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high =n;
        while(low <= high){
            long long mid = low +(high - low)/2;
            long long totalRequired = mid * (mid+1)/2;
            if(totalRequired == n){
                return (int) mid; 
            }
            else if(totalRequired > n){
                high = mid-1;
            }
            else {
                low = mid +1;
            }
        }
        return (int) high;
    }
};