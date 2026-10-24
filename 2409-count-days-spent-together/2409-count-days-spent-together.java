class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int[] daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int aliceArrival = convertToDays(arriveAlice, daysInMonths);
        int aliceLeave = convertToDays(leaveAlice, daysInMonths);
        int bobArrival = convertToDays(arriveBob, daysInMonths);
        int bobLeave = convertToDays(leaveBob, daysInMonths);
        
        int overlapStart = Math.max(aliceArrival, bobArrival);
        int overlapEnd = Math.min(aliceLeave, bobLeave); 
        
        return Math.max(0, overlapEnd - overlapStart + 1); 
    }
    
    private int convertToDays(String date, int[] daysInMonths) {
        int month = Integer.parseInt(date.substring(0, 2));
        int day = Integer.parseInt(date.substring(3, 5));
        
        int totalDays = day;
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonths[i];
        }
        return totalDays;
    }
}
