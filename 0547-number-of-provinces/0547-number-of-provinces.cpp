class Solution {
    private: 
    void dfs(int start , vector<bool>& isVisited , vector<vector<int>>& isConnected){
        isVisited[start] = true;
       for(int j = 0; j < isConnected.size(); j++) {
            // If there is a connection (1) AND the city 'j' hasn't been visited yet
            if(isConnected[start][j] == 1 && !isVisited[j]) {
                dfs(j, isVisited, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num = isConnected.size();
        vector<bool>isVisited(num , false);
        int provinces = 0;

        for(int i= 0;i<num;i++){
            if(!isVisited[i]) {
            dfs(i , isVisited , isConnected);
            provinces++;
        }
        }
        return provinces;
    }
};