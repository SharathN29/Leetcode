// https://leetcode.com/problems/number-of-days-between-two-dates/

class Solution {
    
    private static int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    public int daysBetweenDates(String date1, String date2) {
        int[] d1 = convertStringToDate(date1);
        int[] d2 = convertStringToDate(date2);
        
        int date1Days = d1[0] * 365 + d1[2];
        for (int i = 0; i < d1[1] - 1; i++) {
            date1Days += days[i];
        }
        date1Days += countLeapYear(d1[0], d1[1]);
        
        int date2Days = d2[0] * 365 + d2[2];
        for (int i = 0; i < d2[1] - 1; i++) {
            date2Days += days[i];
        }
        date2Days += countLeapYear(d2[0], d2[1]);
        
        return Math.abs(date1Days - date2Days);
    }
    
    private int[] convertStringToDate(String date) {
        int[] dateArr = new int[3];
        
        String[] d = date.split("-");
        dateArr[0] = Integer.valueOf(d[0]);
        dateArr[1] = Integer.valueOf(d[1]);
        dateArr[2] = Integer.valueOf(d[2]);
        
        return dateArr;
    }
    
    private int countLeapYear(int year, int month) {
        if (month <= 2) {
            year--;
        }
        
        return year / 4 - year / 100 + year / 400;
    }
}
