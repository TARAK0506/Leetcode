class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int endTimehours = (endTime[0] - '0') * 10 + (endTime[1] - '0');
        int startTimeHours = (startTime[0] - '0') * 10 + (startTime[1] - '0');
        int hrs = (endTimehours - startTimeHours) * 60 * 60;

        int endTimeMinutes = (endTime[3] - '0') * 10 + (endTime[4] - '0');
        int startTimeMinutes = (startTime[3] - '0') * 10 + (startTime[4] - '0');
        int min = (endTimeMinutes - startTimeMinutes) * 60;

        int endTimeSec = (endTime[6] - '0') * 10 + (endTime[7] - '0');
        int startTimeSec = (startTime[6] - '0') * 10 + (startTime[7] - '0');
        int seconds = (endTimeSec - startTimeSec);

        return hrs + min + seconds;
    }
};