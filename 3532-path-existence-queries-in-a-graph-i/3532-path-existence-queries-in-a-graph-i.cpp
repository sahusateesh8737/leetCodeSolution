class DisjointSet {
    public:
    vector<int> size, parent;

    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int u){
        if(u==parent[u]) return u;

        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v){
        int p_u = findUPar(u);
        int p_v = findUPar(v);

        if(p_u==p_v) return;
        if(size[p_u]<size[p_v]){
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        }else{
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
};

class Solution {
    public:
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        DisjointSet ds (n);

        for(int r =1;r<n;r++){
            if(nums[r]-nums[r-1] <=maxDiff){
                ds.unionBySize(r,r-1);
            }
        }

        vector<bool> ans (queries.size(),false);

        for(int i =0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];

            ans[i] = ds.findUPar(u)==ds.findUPar(v);
        }

        return ans;
    }
};