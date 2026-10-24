class Solution {
    public int daysBetweenDates(String date1, String date2) {
        return Math.abs(convertToDays(date1) - convertToDays(date2));

    }

    private boolean isLeapYear(int year){
        return (year % 4 ==0 && year % 100 != 0) || (year % 400 == 0);
    }
    private int convertToDays(String date){
            int year = Integer.parseInt(date.substring(0 , 4));
            int month = Integer.parseInt(date.substring(5,7));
            int day = Integer.parseInt(date.substring(8 , 10));
            int days = day;
            for(int i = 1971 ; i < year;i++){
                days +=isLeapYear(i) ? 366 : 365;
            }
            int[] months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            for (int m = 1; m < month; m++) {
            if (m == 2 && isLeapYear(year)) {
                days += 29;
            } else {
                days += months[m];
            }
            }
            return days;
    }

}