class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
       int n = arr.size();
    int left = 0, windowSum = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < n; right++) {
        windowSum += arr[right];  // Expand window

        // Shrink window while condition holds
        while (windowSum >= target) {
            minLen = min(minLen, right - left + 1);
            windowSum -= arr[left++];
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
       
    }
};