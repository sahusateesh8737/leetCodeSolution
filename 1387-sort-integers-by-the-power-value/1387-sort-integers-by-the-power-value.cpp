class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>ans;
        for(int i = lo ;i<=hi;i++){
            int count = 0;
            int x= i;
            while(x!=1){
                if(x%2==0){
                    x = x/2;
                    count++;
                }
                else{
                    x = 3 * x +1;
                    count++;
                }
               
            }
             ans.push_back({count , i});
        }
        sort(ans.begin() , ans.end());
        return ans[k-1].second;
    }
};