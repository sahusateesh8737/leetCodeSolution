class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
         double windowSum  = 0;
         int count  =0;
        for(int i  =0 ;i<k;i++){
            windowSum += nums[i];
        }

        double avg = windowSum /k;
        if(avg >= threshold){
            count++;
        }
       
        for(int i = k ; i < nums.size();i++){
            windowSum  = windowSum + nums[i] - nums[i-k];
            avg  = windowSum/k;
            if(avg >= threshold){
                count++;
            }
           
        }
        return count;
    }
};