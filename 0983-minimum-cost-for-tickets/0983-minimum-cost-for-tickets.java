class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        int[] dp = new int[n + 1];

        for (int i = n - 1; i >= 0; i--) {
            int cost1 = costs[0] + dp[i + 1];

            int j = lowerBound(days, i, days[i] + 7);
            int cost7 = costs[1] + dp[j];

            int k = lowerBound(days, i, days[i] + 30);
            int cost30 = costs[2] + dp[k];

            dp[i] = Math.min(cost1, Math.min(cost7, cost30));
        }

        return dp[0];
    }

    private int lowerBound(int[] days, int left, int target) {
        int right = days.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (days[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
