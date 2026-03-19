class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int , int>lostMap;


        for(int i=0;i<matches.size();i++){
            int loser = matches[i][1];
            lostMap[loser]++;
        }
        vector<int>winners;
        vector<int>losers;

        for(int i=0;i<matches.size();i++){
            int winner = matches[i][0];
            int loser = matches[i][1];
            if(lostMap.find(winner) == lostMap.end()){
                winners.push_back(winner);
                lostMap[winner] = 2;
            }
            if(lostMap[loser] == 1){
                losers.push_back(loser);
            }
        }
        sort(winners.begin() , winners.end());
        sort(losers.begin() , losers.end());
        return {winners , losers};
    }
};