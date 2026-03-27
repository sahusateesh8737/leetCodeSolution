class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>>adj(n+1);
        // first we will make adjacency list see the edge connection;
        for(auto it :edges){
            int u = it[0];
            int v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=-1;
        int maxi = 0;
        for(int i = 1 ;i<=n;i++){
            if(adj[i].size() > maxi){
                maxi = adj[i].size();
                ans = i;
            }
        }
        return ans;
    }
};