class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int ans =0;
        int alti=0;
        for(int i=0;i<n;i++){
            alti = alti+gain[i];
            ans = max(ans,alti);
        }
        return ans;
    }
};