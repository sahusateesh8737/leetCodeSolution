class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<long long>> indices_map;
        for (int i = 0; i < n; i++) {
            indices_map[nums[i]].push_back(i);
        }

        for (auto& [val, indices] : indices_map) {
            int k = indices.size();
            if (k == 1)
                continue; // If it only appears once, distance is 0

            long long totalSum = 0;
            for (long long idx : indices) {
                totalSum += idx;
            }

            long long leftSum = 0;
            for (int m = 0; m < k; m++) {
                long long currentIdx = indices[m];

                long long rightSum = totalSum - leftSum - currentIdx;

                long long leftDistance = (m * currentIdx) - leftSum;

                long long rightDistance = rightSum - ((k - 1 - m) * currentIdx);

                ans[currentIdx] = leftDistance + rightDistance;
                leftSum += currentIdx;
            }
        }

        return ans;
    }
};