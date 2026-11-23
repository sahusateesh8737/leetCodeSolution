class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return 1;

        if (nums[0] >= nums[1]) {
            count++;
        }

        if (nums[n - 1] >= nums[n - 2]) {
            count++;
        }

        for (int i = 1; i < n - 1; i++) {
           
            if (2LL * nums[i] >= 1LL * nums[i - 1] + nums[i + 1]) {
                count++;
            }
        }

        return count;
    }
};