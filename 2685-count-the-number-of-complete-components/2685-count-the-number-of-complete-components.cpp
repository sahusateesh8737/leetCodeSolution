class Solution {
private: 
 
    void dfs(int u, vector<vector<int>>& graph, vector<bool>& visited, int& nodeCount, int& edgeCount) {
        visited[u] = true;
        nodeCount++;
        edgeCount += graph[u].size(); // Add the degree of the current node
        
        for(auto v : graph[u]){
            if(visited[v]) continue;
            dfs(v, graph, visited, nodeCount, edgeCount);
        }
    }

public:
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        //You must declare the graph and visited arrays first!
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        
        //Build the adjacency list from the given edges
        for(int i = 0; i < edges.size(); i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        } 
        
       
        int count = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue; // Skip if already visited
            
            int nodeCount = 0;
            int edgeCount = 0;
            
            //Explore the whole component
            dfs(i, graph, visited, nodeCount, edgeCount);
            
            // Check if complete
            if (edgeCount == nodeCount * (nodeCount - 1)) {
                count++;
            }
        }
        
        return count;
    }
};