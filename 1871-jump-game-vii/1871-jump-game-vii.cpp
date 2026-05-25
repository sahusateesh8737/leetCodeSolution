class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        // If the last character is '1', we can never reach it.
        if (s[n - 1] == '1') {
            return false;
        }
        
        // dp[i] will be true if we can reach index i
        vector<bool> dp(n, false);
        dp[0] = true; // We always start at index 0
        
        // This keeps track of how many reachable positions are in our current window
        int reachable_in_window = 0; 
        
        for (int i = 1; i < n; ++i) {
            // 1. Add the index that just entered our valid window (i - minJump)
            if (i >= minJump && dp[i - minJump]) {
                reachable_in_window++;
            }
            
            // 2. Remove the index that just fell out of our valid window (i - maxJump - 1)
            if (i > maxJump && dp[i - maxJump - 1]) {
                reachable_in_window--;
            }
            
            // 3. If there is at least one valid take-off spot in the window, 
            // and our current landing spot is a '0', we can reach this index.
            if (reachable_in_window > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }
        
        return dp[n - 1];
    }
};