class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int totalWaviness = 0;
        
        // Iterate through the inclusive range
        for (int i = num1; i <= num2; ++i) {
            int n = i;
            
            // Any number with fewer than 3 digits has 0 waviness
            if (n < 100) continue; 
            
            // Initialize the rightmost and middle digits
            int right = n % 10;
            n /= 10;
            int mid = n % 10;
            n /= 10;
            
       
            while (n > 0) {
                int left = n % 10;
                
               
                if ((mid > left && mid > right) || (mid < left && mid < right)) {
                    totalWaviness++;
                }
             
                right = mid;
                mid = left;
                n /= 10;
            }
        }
        
        return totalWaviness;
    }
};