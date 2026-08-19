class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
            int tx = target[0], ty = target[1];
    int bestIdx = -1;
    int bestDist = INT_MAX;
    
    for (int i = 0; i < drones.size(); i++) {
        int x = drones[i][0];
        int y = drones[i][1];
        int range = drones[i][2];
        
        int dist = abs(x - tx) + abs(y - ty);
        
        if (dist <= range) {
            if (dist < bestDist) {
                bestDist = dist;
                bestIdx = i;
            }
        }
    }
    
    return bestIdx;
    }
};