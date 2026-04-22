class Solution {
public:
int rever(int num){
    int newNum = 0;
   
    while(num >0){
        int rem = num %10;
        newNum = newNum *10 + rem;
        num = num /10;
    }
    return newNum;
}
    bool sumOfNumberAndReverse(int num) {
        if(num ==0) return true;
       for(int i =1;i<=num;i++ ){
        int sum = i + rever(i);
        if(sum == num){
        return true;
        }
      
    }
   return false;
    }
};