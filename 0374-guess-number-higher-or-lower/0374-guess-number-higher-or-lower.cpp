/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int h = n;
        while(l<=h){
            int guessNumber =l+(h-l)/2;
            int val = guess(guessNumber);
            if(val == 0){
                return guessNumber;
            }
            else if(val == -1){
                h = guessNumber-1;
            }
            else {
                l= guessNumber+1;
            }
        }
        return -1;
    }
};