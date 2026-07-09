class Solution {
public:
    int maxValidPairSum(vector<int>& arr, int k) {
        int n = arr.size();
    vector<int> suffixMax(n);

    suffixMax[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(arr[i], suffixMax[i + 1]);
    }
    
 

    int ans = INT_MIN;

    for (int i = 0; i + k < n; i++) {
        ans = max(ans, arr[i] + suffixMax[i + k]);

    }
    return ans;
    }
};