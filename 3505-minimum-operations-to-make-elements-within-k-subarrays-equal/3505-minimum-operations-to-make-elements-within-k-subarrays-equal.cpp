#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int m = n - x + 1;
        vector<long long> cost(m);

        multiset<long long> left, right;
        long long sum_left = 0, sum_right = 0;

        auto rebalance = [&]() {
            while (left.size() < right.size()) {
                long long val = *right.begin();
                right.erase(right.begin());
                sum_right -= val;
                left.insert(val);
                sum_left += val;
            }
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                long long val = *it;
                left.erase(it);
                sum_left -= val;
                right.insert(val);
                sum_right += val;
            }
        };

        auto add = [&](long long val) {
            if (left.empty() || val <= *prev(left.end())) {
                left.insert(val);
                sum_left += val;
            } else {
                right.insert(val);
                sum_right += val;
            }
            rebalance();
        };

        auto remove = [&](long long val) {
            auto it_left = left.find(val);
            if (it_left != left.end()) {
                left.erase(it_left);
                sum_left -= val;
            } else {
                auto it_right = right.find(val);
                right.erase(it_right);
                sum_right -= val;
            }
            rebalance();
        };

       
        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                long long median = *prev(left.end());
                long long left_cost = median * (long long)left.size() - sum_left;
                long long right_cost = sum_right - median * (long long)right.size();
                cost[i - x + 1] = left_cost + right_cost;
            }
        }

       
        const long long INF = 1e18;
        vector<long long> prev_dp(m, 0); 

        for (int j = 1; j <= k; ++j) {
            vector<long long> curr_dp(m, INF);
            for (int i = (j - 1) * x; i < m; ++i) {
              
                if (i > 0) {
                    curr_dp[i] = curr_dp[i - 1];
                }
               
                long long prev_cost = (j == 1) ? 0 : (i >= x ? prev_dp[i - x] : INF);
                if (prev_cost != INF) {
                    curr_dp[i] = min(curr_dp[i], prev_cost + cost[i]);
                }
            }
            prev_dp = move(curr_dp);
        }

        return prev_dp[m - 1];
    }
};
