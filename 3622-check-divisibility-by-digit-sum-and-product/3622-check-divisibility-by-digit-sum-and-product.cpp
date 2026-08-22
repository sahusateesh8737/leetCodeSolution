class Solution {
public:
    int sum(int n){
        int s = 0;
        int p =1;
        int temp = n;
        while(temp > 0){
            int r  = temp %10;
            s = s + r;
            p = p * r;
            temp = temp / 10;
        }
        return s+p;
    }
    bool checkDivisibility(int n) {
        int r  = sum(n);
        if(n % r == 0){
            return true;
        }
        return false;
        
    }
};