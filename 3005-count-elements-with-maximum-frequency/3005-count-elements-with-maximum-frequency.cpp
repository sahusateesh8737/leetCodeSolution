class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int maxFreq = 0;
        int totalCount =0;
        for(int num : nums){
            freq[num]++;
            if(freq[num] > maxFreq){
                maxFreq = freq[num];
                totalCount = freq[num];
            }
            else if(freq[num] == maxFreq) {
                totalCount += freq[num];
            }
        }
        return totalCount;
    }
};