//Approach: 
//We're basically adding all the activites that start on a same given day.
//Out of these we now attend the one which ends at the earliest possible.
//We increment the day and hence remove all the activites which coudn't be attended.


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(events.begin(),events.end());
        int i=0,day,res=0,n=size(events);
        
        while(pq.size() || i<n)
        {
            if(pq.size() == 0)
                day = events[i][0];
            
            while(i<n && events[i][0] == day)
                pq.push(events[i++][1]);
            
            //Attending the activity ending at the earliest.
            pq.pop();
            res++,day++;
            
            //Removing all the activites which now coudn't be attended
            
            while(pq.size()>0 && pq.top()<day)
                pq.pop();
        }
        return res;
    }
};//Approach: 
//We're basically adding all the activites that start on a same given day.
//Out of these we now attend the one which ends at the earliest possible.
//We increment the day and hence remove all the activites which coudn't be attended.


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(events.begin(),events.end());
        int i=0,day,res=0,n=size(events);
        
        while(pq.size() || i<n)
        {
            if(pq.size() == 0)
                day = events[i][0];
            
            while(i<n && events[i][0] == day)
                pq.push(events[i++][1]);
            
            //Attending the activity ending at the earliest.
            pq.pop();
            res++,day++;
            
            //Removing all the activites which now coudn't be attended
            
            while(pq.size()>0 && pq.top()<day)
                pq.pop();
        }
        return res;
    }
};