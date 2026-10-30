class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (n==1) return 0;
        vector<vector<pair<int ,int >>> adj(n);
        for(const auto& e : edges){
            adj[e[0]].push_back({e[1] , e[2]});
        }
        vector<long long > dist(n * (k+1) , LLONG_MAX);
        vector<int>min_c(n , k+1);
        using State = tuple<long long , int ,int>;
        priority_queue<State , vector<State> , greater<State>>pq;
        dist[0 * (k + 1) + 1] = 0;
        pq.push({ 0 , 0,1});
        while(!pq.empty()){
            auto[d , u  , c] = pq.top();
            pq.pop();
            if(u == n-1) return d;
            if(c >= min_c[u]) continue;
            min_c[u] = c;
            for(auto [v,w] : adj[u]){
                int nc = (labels[v] == labels[u]) ?  c + 1 : 1;
                if(nc <= k && nc < min_c[v]){
                    long long nd = d + w;
                    int idx = v * (k + 1) + nc;
                    if(nd < dist[idx]){
                        dist[idx] = nd ;
                        pq.push({nd , v , nc});
                    }
                }
            }
        }
        return -1;
    }
};