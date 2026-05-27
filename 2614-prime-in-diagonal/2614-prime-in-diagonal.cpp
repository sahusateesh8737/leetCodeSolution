class Solution {
public:
bool isPrime(int n) {
  
    if (n <= 1)
        return false;

    if (n == 2 || n == 3)
     return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i *i<=n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxnum= 0;
        for(int i =0;i<n;i++){
            if(isPrime(nums[i][i])){
                maxnum = max(maxnum , nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1])) {
                maxnum = max(maxnum, nums[i][n - i - 1]);
            }
        }
    return maxnum;
    }
};