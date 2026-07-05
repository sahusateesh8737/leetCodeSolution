class Solution {
public:
        int memo[1001];
    int solver(vector<int>&cost ,  int i , int n ){
        if(i >= n){
            return 0;
        }
        if(memo[i] !=-1){
            return memo[i];
        }
        int res = cost[i] + min(solver(cost , i+1 ,n ) , solver(cost , i+2 , n));
       
        return memo[i]  = res;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

    memset(memo , -1 , sizeof(memo));
        int solve0 = solver(cost,  0 , n);

        int solve1 = solver(cost , 1, n);
        return min(solve0 , solve1);
    }
};