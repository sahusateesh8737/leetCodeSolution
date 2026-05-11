class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long windowSum = 0;
        long long maxSum = 0;
        
        unordered_map<int, int> freqMap; 

        for (int i = 0; i < nums.size(); i++) {
            
            windowSum += nums[i];
            freqMap[nums[i]]++;

     
            if (i >= k) {
                int leftElement = nums[i - k];
                windowSum -= leftElement; 
                freqMap[leftElement]--;  
                
                if (freqMap[leftElement] == 0) {
                    freqMap.erase(leftElement);
                }
            }

            if (i >= k - 1) {
              
                if (freqMap.size() == k) {
                    maxSum = max(maxSum, windowSum);
                }
            }
        }

        return maxSum;
    }
};