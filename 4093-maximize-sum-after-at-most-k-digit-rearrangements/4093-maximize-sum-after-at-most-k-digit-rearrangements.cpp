class Solution {
    long long getMaxVal(int x ){
        int count[10] = {0};
        while(x > 0){
            count[x % 10]++;
            x /= 10;
        }
        long long res = 0;
        for(int d = 9 ; d >= 0; d--){
            while(count[d]-- > 0){
                res = res * 10 + d;
            }
        }
        return res;
    }
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long total_sum = 0;
        vector<long long> gains(n);
        for(int i = 0;i < n ;i++){
            total_sum += nums[i];
            gains[i] = getMaxVal(nums[i]) - nums[i];

        }
        if( k < n){
            nth_element(gains.begin() , gains.begin()+ k , gains.end() , greater<long long>());

        }
        for(int i = 0; i < k;i++){
            total_sum += gains[i];
        }
        return total_sum;
    }
};