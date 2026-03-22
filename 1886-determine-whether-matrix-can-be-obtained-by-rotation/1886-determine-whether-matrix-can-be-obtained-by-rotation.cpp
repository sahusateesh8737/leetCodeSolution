class Solution {
public:
void rotate(vector<vector<int>>&mat){

        // for transposing
    for(int i = 0;i< mat.size();i++){
            for(int j = i+1;j<mat.size();j++){
                swap(mat[i][j] , mat[j][i]);
            }
            
        }

        // here we will reverse;
        for(int i = 0;i< mat.size();i++){
            reverse(mat[i].begin() , mat[i].end());
        }
        
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int r= 1 ;r<=4;r++){
         bool equal = true;
         for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] != target[i][j]){
                    equal = false;
                    break;
                }
            }
            if(!equal){
                break;
            }
         }
         if(equal){
            return true;
         }
    rotate(mat);
        }
        return false;
    }
};