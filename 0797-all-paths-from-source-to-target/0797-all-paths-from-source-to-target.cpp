class Solution {
public:

        void dfs(vector<vector<int>>& graph , int sr , int des , vector<vector<int>>& ans, vector<int>&temp){
            temp.push_back(sr);
            if(sr== des){
                ans.push_back(temp);
            }
            else{
                for(auto it : graph[sr]){
                    dfs(graph , it , des , ans , temp);
                }
            }
            temp.pop_back();
        }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int source  = 0;
        int dest = n-1;
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(graph , source , dest  , ans , temp);
        return ans;
    }
};