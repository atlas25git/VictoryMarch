class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        sort(intervals.begin(),intervals.end(),
        [](Interval a,Interval b){if(a.start == b.start)return a.end<b.end; else return a.start<b.start;});
        bool flag=true;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i-1].end>intervals[i].start)
                return false;
        }
        return true;
    }
};