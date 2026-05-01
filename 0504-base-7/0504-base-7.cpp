class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        bool isNegative = false;

        if(num < 0){
            isNegative = true;
            num = abs(num);
        }
        string ans= "";

        while(num >0){
            int remainder = num %7;
            ans = ans + to_string(remainder);
            num = num /7;
        }
        if(isNegative){
            ans =  ans +  "-";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};