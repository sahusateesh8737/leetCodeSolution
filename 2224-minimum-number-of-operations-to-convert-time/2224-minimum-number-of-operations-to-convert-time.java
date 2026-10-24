class Solution {
    public int convertTime(String current, String correct) {
        int currentMinutes = timeToMinutes(current);
        int correctMinutes = timeToMinutes(correct);
        int diff = correctMinutes - currentMinutes;
        int operations = 0;
        int[] increments = {60 , 15 , 5 , 1};
        for(int inc : increments){
            operations += diff / inc;
            diff %= inc;
        }
        return operations;
    }
    private int timeToMinutes(String time){
        int hours = Integer.parseInt(time.substring(0 , 2));
        int minutes = Integer.parseInt(time.substring(3, 5));
        return hours * 60 + minutes;
    }
}