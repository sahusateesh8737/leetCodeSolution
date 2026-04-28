class Solution {
public:
    vector<int> leftRightDifference(vector<int>& arr) {
        vector<int>leftSum;
        vector<int>rightSum;
        vector<int>ans;
        int lsum =0;
        int rsum = 0;
        leftSum.push_back(lsum);

        // loop for left sum
        for(int i=1;i<arr.size();i++){
            lsum = lsum + arr[i-1];
            leftSum.push_back(lsum);
        }
        // loop for right sum
        
        rightSum.push_back(rsum);
    for(int i=arr.size()-1;i>0;i--){
        rsum = rsum+ arr[i];
        rightSum.push_back(rsum);
    }

       reverse(rightSum.begin(), rightSum.end());

        for(int i=0;i<leftSum.size();i++){
        ans.push_back(abs(leftSum[i] - rightSum[i]));
    }
    return ans;

    }
};