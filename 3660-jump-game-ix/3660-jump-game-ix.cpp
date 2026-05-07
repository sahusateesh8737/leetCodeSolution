#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        // Fast I/O to shave off any standard input/output overhead
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        vector<int> parent(n);
        vector<int> max_val(n);
        vector<int> sz(n, 1); // Track the size of each component

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            max_val[i] = nums[i];
        }

        // 1. Iterative Find with Path Compression (Zero recursion overhead)
        auto find_set = [&](int v) {
            int root = v;
            // Find the actual root
            while (root != parent[root]) {
                root = parent[root];
            }
            // Compress the path iteratively
            int curr = v;
            while (curr != root) {
                int nxt = parent[curr];
                parent[curr] = root;
                curr = nxt;
            }
            return root;
        };

        // 2. Union by Size
        auto union_sets = [&](int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b) {
                // Always attach the smaller tree under the larger tree
                if (sz[a] < sz[b]) {
                    swap(a, b);
                }
                parent[b] = a;
                sz[a] += sz[b];
                max_val[a] = max(max_val[a], max_val[b]);
            }
            return a;
        };

        vector<int> st; // Monotonic stack for component roots

        for (int i = 0; i < n; ++i) {
            int curr_root = i;
            
            while (!st.empty() && max_val[st.back()] > nums[i]) {
                int top_root = st.back();
                st.pop_back();
                curr_root = union_sets(curr_root, top_root);
            }
            
            st.push_back(curr_root);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = max_val[find_set(i)];
        }

        return ans;
    }
};