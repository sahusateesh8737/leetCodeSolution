#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Fenwick {
        int n;
        vector<int> tree;
        Fenwick(int n) : n(n), tree(n + 1, 0) {}

        void add(int i, int delta) {
            for (; i <= n; i += i & -i)
                tree[i] += delta;
        }

        int query(int i) const {
            int sum = 0;
            for (; i > 0; i -= i & -i)
                sum += tree[i];
            return sum;
        }
    };

public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int unlocks = 0;
        int pref_max = 0;

      
        for (int i = 0; i < n; ++i) {
            if (locked[i] == 1) {
             
                if (nums[i] != i + 1 || pref_max > i) {
                    unlocks++;
                }
            }
            pref_max = max(pref_max, nums[i]);
        }

        if (unlocks > k) {
            return -1;
        }

       
        Fenwick bit(n);
        long long swaps = 0;
        for (int i = 0; i < n; ++i) {
       
            swaps += i - bit.query(nums[i]);
            bit.add(nums[i], 1);
        }

        return unlocks + swaps;
    }
};
