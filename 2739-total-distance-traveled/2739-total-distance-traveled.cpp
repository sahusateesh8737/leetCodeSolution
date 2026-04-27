class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        for(int i=1;i<=mainTank;i++){
            if(additionalTank!=0 && i%5==0){
                additionalTank--;
                res+=10;
                mainTank++;
            }else{
                res+=10;
            }
        }
        return res;
    }
};