class Solution {
public:
    int digitSum(int n){
    int sum = 0 ;
    while(n > 0){
        int remainder = n % 10 ;
        sum += remainder ;
        n = n / 10 ;
    }
    return sum;
    }

    int countEven(int num) {
        int count = 0;
        for(int i =1 ; i<=num;i++){
            int sum = digitSum(i);
            if(sum %2 ==0){
                count++;
            }
        }
        return count;
    }
};