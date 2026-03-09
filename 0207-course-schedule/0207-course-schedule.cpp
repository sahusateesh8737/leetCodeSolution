class Solution {
public:
   bool topologicalSortCheck(unordered_map<int , vector<int>> &adj , int n , vector<int>&indegree){
    queue<int> que;
    int count = 0;

    // 1. Initial scan: Find ALL nodes with 0 indegree first
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            que.push(i);
        }
    }

    // 2. Process the queue (BFS)
    while(!que.empty()){
        int u = que.front();
        que.pop();
        count++; // Increment count when a node is "removed" from the graph

        for(int &v : adj[u]){
            indegree[v]--;  
            if(indegree[v] == 0){
                que.push(v);
            }
        }
    }

    // If count == n, it's a Directed Acyclic Graph (DAG)
    return count == n;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , vector<int>> adj;
        vector<int>indegree(numCourses , 0);
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topologicalSortCheck(adj , numCourses , indegree);
    }
};