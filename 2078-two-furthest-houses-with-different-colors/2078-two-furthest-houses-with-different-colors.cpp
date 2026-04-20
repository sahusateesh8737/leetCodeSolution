class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int left = 0;
        int right = n - 1;
       
        while (colors[0] == colors[right]) {
            right--;
        }
       
        while (colors[n - 1] == colors[left]) {
            left++;
        }
        
        return max(right, (n - 1) - left);
    }
};