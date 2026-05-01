class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int func = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            func += i * nums[i];
        }

        int maxi = func;

        for(int k = 1; k < n; k++){
            func = func + sum - n * nums[n - k];
            maxi = max(maxi, func);
        }

        return maxi;
    }
};