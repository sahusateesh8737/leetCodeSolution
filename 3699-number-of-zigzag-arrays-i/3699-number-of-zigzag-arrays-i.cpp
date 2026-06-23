

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD = 1e9 + 7;
        int K = r - l + 1;
        
        // Edge cases
        if (K < 1) return 0;
        if (n == 1) return K; 

        // Base case: Length 2
        std::vector<long long> dp_up(K + 1, 0);
        std::vector<long long> dp_down(K + 1, 0);

        // For a sequence of length 2:
        // Any pair (A[0], A[1]) where A[0] < A[1] is a valid "up" ending at A[1] = j.
        // There are exactly (j - 1) choices for A[0].
        // Similarly, for "down" ending at A[1] = j, there are (K - j) choices.
        for (int j = 1; j <= K; ++j) {
            dp_up[j] = j - 1;
            dp_down[j] = K - j;
        }

        // Build the sequence up to length n
        for (int i = 3; i <= n; ++i) {
            std::vector<long long> next_up(K + 1, 0);
            std::vector<long long> next_down(K + 1, 0);

            // Compute prefix sums for next_up
            long long prefix_down = 0;
            for (int j = 1; j <= K; ++j) {
                next_up[j] = prefix_down;
                prefix_down = (prefix_down + dp_down[j]) % MOD;
            }

            // Compute suffix sums for next_down
            long long suffix_up = 0;
            for (int j = K; j >= 1; --j) {
                next_down[j] = suffix_up;
                suffix_up = (suffix_up + dp_up[j]) % MOD;
            }

            // Move to the next sequence length
            dp_up = next_up;
            dp_down = next_down;
        }

        // Aggregate the total valid sequences
        long long total = 0;
        for (int j = 1; j <= K; ++j) {
            total = (total + dp_up[j] + dp_down[j]) % MOD;
        }

        return total;
    }
};