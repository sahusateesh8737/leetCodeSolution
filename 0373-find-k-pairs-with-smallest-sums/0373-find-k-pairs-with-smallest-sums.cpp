


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) return ans;

        // Min-heap to store: {sum, index_in_nums1, index_in_nums2}
        // We use a custom comparator to ensure the smallest sum stays at the top.
        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b); 
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);

        // Optimization: We only need to start with at most 'k' elements from nums1
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            // If there's a next element in nums2 for the current nums1[i], push it into the heap
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};