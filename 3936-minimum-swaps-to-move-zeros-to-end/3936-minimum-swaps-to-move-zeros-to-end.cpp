class Solution {
public:
    int minimumSwaps(vector<int>& arr) {
        int n = arr.size();
        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zeroCount++;
            }
        }
        int swap = 0;
        for (int i = n - zeroCount; i < n; i++) {
            if (arr[i] != 0) {
                swap++;
            }
        }
        return swap;
    }
};