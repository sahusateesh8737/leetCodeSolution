class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n + 1];
        for(int row = n-1; row >= 0; row--){
            List<Integer> currentRow = triangle.get(row);
            for(int col = 0;col <= row; col++){
                dp[col] = currentRow.get(col) + Math.min(dp[col] , dp[col + 1]);
            }
        }
        return dp[0];
    }
}