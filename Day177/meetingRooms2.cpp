struct cmp{
    bool operator()(Interval a,Interval b)
    {
        if(a.end == b.end)return a.start>b.start;
        else return a.end>b.end;
    }
};

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        if(intervals.size() == 0)return 0;
        priority_queue<Interval,vector<Interval>,cmp> pq;
        
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b)
        {if(a.start == b.start)return a.end<b.end;
        else return a.start<b.start;});

        int rooms = 0;
        pq.push(intervals[0]);
        rooms++;

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start < pq.top().end)
                rooms++;
            else pq.pop();

            pq.push(intervals[i]);
        }

        return rooms;
    }
};