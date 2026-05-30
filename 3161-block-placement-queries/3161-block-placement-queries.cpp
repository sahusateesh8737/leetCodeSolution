class Solution {
    // Segment Tree jo range [L, R] ka maximum gap track karegi
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // Step 1: Max coordinate x dhoondhte hain constraints ke hisab se
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        // Segment Tree ka size max_x ke base par set karte hain
        n = max_x + 1;
        tree.assign(4 * n, 0);
        
        // Obstacles ko track karne ke liye set
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(n); // Boundary condition
        
        // Shuruat mein koi obstacle nahi hai, toh 0 se n tak ka gap 'n' hai
        update(1, 0, n, n, n);
        
        vector<bool> results;
        
        for (const auto& q : queries) {
            int type = q[0];
            
            if (type == 1) {
                int x = q[1];
                
                // x ke just baad aur pehle wale obstacles ko dhoondho
                auto it = obstacles.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);
                
                obstacles.insert(x);
                
                // Gaps ko split karo aur Segment Tree mein update karo
                update(1, 0, n, x, x - prev_obs);
                update(1, 0, n, next_obs, next_obs - x);
                
            } else {
                int x = q[1];
                int sz = q[2];
                
                // 1. [0, x] ke beech pehle se majood gaps ka maximum nikalo
                int max_gap_inside = query(1, 0, n, 0, x);
                
                // 2. x aur uske just pehle wale obstacle ke beech ka gap nikalo
                auto it = obstacles.upper_bound(x);
                int prev_obs = *prev(it);
                int last_gap = x - prev_obs;
                
                // Dono mein se jo sabse bada gap ho
                int total_max_gap = max(max_gap_inside, last_gap);
                
                // Agar total_max_gap block size se bada ya barabar hai
                results.push_back(total_max_gap >= sz);
            }
        }
        
        return results;
    }
};