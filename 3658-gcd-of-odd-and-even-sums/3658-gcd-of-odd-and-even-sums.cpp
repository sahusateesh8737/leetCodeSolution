class Solution {
public:


int gcde(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int sumEven = 0;
        int sumOdd = 0;
        for(int i=1;i<=n*2;i++){
            if(i%2 ==0){
                sumEven = sumEven + i;
            }
            else {
                sumOdd = sumOdd + i;
            }
        }
       int gc =  gcde(sumEven,sumOdd);
       return gc;
    }
};