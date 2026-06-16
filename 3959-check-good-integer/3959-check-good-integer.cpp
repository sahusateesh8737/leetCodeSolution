class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum = 0;
        int sqr = 0;
        while(n>0){
            int q = n % 10;
            n = n/10;
            sum = sum + q;
            sqr = sqr + (q * q);
        }
       if(sqr - sum >= 50){
        return true;
       }
       else {
        return false;
       }
    }
};