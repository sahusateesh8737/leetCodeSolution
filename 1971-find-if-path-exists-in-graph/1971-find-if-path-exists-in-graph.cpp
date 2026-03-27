class Solution {
public:
    bool dfs(int sr , int des , vector<vector<int>>&adj , vector<bool>&vis){
        if(sr == des){
            return true;
        }
        vis[sr] = true;
        for(auto it : adj[sr]){
            if(!vis[it]){
                if(dfs(it , des , adj , vis)){
                    return true;
                }
            }
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination){
            return true;
        }
        // adjacency list
        vector<vector<int>>adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
             adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>vis(n , false);
        return dfs(source , destination , adj , vis);
    }
};