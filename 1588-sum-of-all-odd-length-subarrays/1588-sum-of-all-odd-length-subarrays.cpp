class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int total_sum = 0;
        
        for (int i = 0; i < n; i++) {
           
            int total_subarrays = (i + 1) * (n - i);
            int odd_subarrays = (total_subarrays + 1) / 2;
            
            total_sum += arr[i] * odd_subarrays;
        }
        
        return total_sum;
    }
};