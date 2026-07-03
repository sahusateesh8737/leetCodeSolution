#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    
    bool canReach(int min_edge_cost, int n, long long k, 
                  const vector<vector<pair<int, int>>>& adj, const vector<bool>& online) {
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 2e18); 
        
        pq.push({0, 0});
        dist[0] = 0;
        
        while(!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(d > dist[u]) continue;
            if(u == n - 1) return true; 
            
            for(auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if(weight >= min_edge_cost && online[v]) {
                    if(dist[u] + weight <= k && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int max_possible_cost = 0;
    
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            max_possible_cost = max(max_possible_cost, edge[2]);
        }
        
        int low = 0, high = max_possible_cost;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canReach(mid, n, k, adj, online)) {
                ans = mid;   
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
        
        return ans;
    }
};