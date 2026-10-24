class ATM {
    private long[] bank;
    private int[] values = {20, 50, 100, 200, 500};

    public ATM() {
        bank = new long[5];
    }
    
    public void deposit(int[] banknotesCount) {
        for (int i = 0; i < 5; i++) {
            bank[i] += banknotesCount[i];
        }
    }
    
    public int[] withdraw(int amount) {
        long[] temp = bank.clone();
        int[] result = new int[5]; // Fixed array declaration
        
        for (int i = 4; i >= 0; i--) {
            if (amount <= 0) break;
            long count = Math.min(amount / values[i], temp[i]);
            result[i] = (int) count;
            amount -= count * values[i];
            temp[i] -= count;
        }

        if (amount > 0) {
            return new int[]{-1};
        }
        
        bank = temp;
        return result;
    }
}
