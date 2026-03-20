class Solution {
public:
    int M = 1e9 + 7;

    int rev(int num) {
        int re = 0;
        while (num > 0) {
            int remainder = num % 10;
            re = (re * 10) + remainder;
            num = num / 10;
        }
        return re;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;

        // transform array
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            result = (result + mp[nums[i]]) % M;
            mp[nums[i]]++;
        }

        return result;
    }
};