class Solution {
public:
    int getLucky(string s, int k) {
        string number = "";
        for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        // Agar character lowercase hai (a to z)
        if (ch >= 'a' && ch <= 'z') {
            int position = ch - 'a' + 1;
            number += to_string(position);
           
        } 
         }
        int currentsum = 0;

        while(k>0){
            currentsum = 0;
            for (int i = 0; i < number.length(); i++) {
                currentsum += (number[i] - '0'); 
            }
            number = to_string(currentsum);
            k--;

        }
    
    return currentsum;
    }
};