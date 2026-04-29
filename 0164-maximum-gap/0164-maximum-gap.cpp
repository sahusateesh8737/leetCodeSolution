class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n <2) return 0;
        int maxi =0;
        sort(nums.begin() , nums.end());
        for(int i =0;i<n-1;i++){
            maxi = max(maxi , abs(nums[i] - nums[i+1]));
        }
        return maxi;
    }
};