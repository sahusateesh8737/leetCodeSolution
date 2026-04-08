class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int left=findfirst(nums,target);
        int right=findlast(nums,target);

         
         return {left , right};
        
    }
private:
    int findfirst(const vector<int>& nums , int target){
         int low=0;
        int high=nums.size()-1;
        int left=-1;
        
        while(low<=high){
            int mid=low +(high-low)/2;
            if(nums[mid]==target){
                left= mid;
                high=mid-1;
     }

            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return left;
    }

    int findlast(const vector<int>& nums , int target){
         int low=0;
        int high=nums.size()-1;
        int right=-1;
        
        while(low<=high){
            int mid=low +(high-low)/2;
            if(nums[mid]==target){
                right=mid;
                low=mid+1;
            }

            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
    

    return right;}

};