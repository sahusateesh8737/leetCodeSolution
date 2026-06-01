class Solution {
public:
    int minimumCost(vector<int>& cost) {
         sort(cost.rbegin(), cost.rend());
        int totalcost = 0;
     
        for(int i = 0;i<cost.size();i++){
            if((i+1 )% 3 != 0){
                totalcost += cost[i];
            }
        }
        return totalcost;
    }
};