class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            
            // Jab tak numbers lagatar aa rahe hain, aage badhte raho
            // Integer overflow se bachne ke liye long long use kiya hai
            while (i + 1 < n && (long long)nums[i + 1] == (long long)nums[i] + 1) {
                i++;
            }
            
            // Loop khatam hone par nums[i] hamari range ka last element hoga
            if (start == nums[i]) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        
        return result;

    }
};