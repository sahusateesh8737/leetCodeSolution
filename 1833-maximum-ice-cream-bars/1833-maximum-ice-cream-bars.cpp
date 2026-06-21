class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int iceCream = 0;
        for (int i = 0; i < n; i++) {
            if(costs[i] > coins){
                return iceCream;
            }
            coins = coins - costs[i];
            iceCream++;
        }
        return iceCream;
    }
};