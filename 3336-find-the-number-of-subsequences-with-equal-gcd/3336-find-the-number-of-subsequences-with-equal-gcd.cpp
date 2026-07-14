#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        

        dp[0][0] = 1;
        
        for (int x : nums) {
         
            vector<vector<int>> next_dp = dp; 
            
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;
                    
                    int current_ways = dp[g1][g2];
                    
                 
                    int next_g1 = std::gcd(g1, x);
                    next_dp[next_g1][g2] = (next_dp[next_g1][g2] + current_ways) % MOD;
                    
          
                    int next_g2 = std::gcd(g2, x);
                    next_dp[g1][next_g2] = (next_dp[g1][next_g2] + current_ways) % MOD;
                }
            }
            

            dp = next_dp;
        }
        
        int total_pairs = 0;
        for (int i = 1; i <= max_val; ++i) {
            total_pairs = (total_pairs + dp[i][i]) % MOD;
        }
        
        return total_pairs;
    }
};