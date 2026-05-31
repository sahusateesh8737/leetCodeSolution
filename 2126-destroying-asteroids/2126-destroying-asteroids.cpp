class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin() , asteroids.end());
        long long currentSum = mass;
        for(int i = 0;i<asteroids.size();i++){
            if(currentSum >= asteroids[i]){
                currentSum += asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};