class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int , int>>scorePair;
        vector<string>ans(n);
        for(int i  = 0;i<n;i++){
            scorePair.push_back({score[i] , i});
        }
        sort(scorePair.rbegin() , scorePair.rend());
       for (int i = 0; i < n; i++) {
            int originalIndex = scorePair[i].second; // Puraane index ko nikal rahe hain
            
            if (i == 0) {
                ans[originalIndex] = "Gold Medal";
            } else if (i == 1) {
                ans[originalIndex] = "Silver Medal";
            } else if (i == 2) {
                ans[originalIndex] = "Bronze Medal";
            } else {
                ans[originalIndex] = to_string(i + 1); // 4th place aur uske aage
            }
        }
        
        return ans;

    }
};