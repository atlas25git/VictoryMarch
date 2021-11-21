class Solution {
public:
    unordered_map<int,int> memo;
    int jobScheduling1(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i=0;i<profit.size();i++)
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        
        sort(jobs.begin(),jobs.end());
        return maxPro(0,jobs);
    }
    
    int maxPro(int cur,vector<vector<int>>& jobs)
    {
        if(cur == jobs.size())return 0;
        
        if(memo.count(cur))return memo[cur];
        
        int next = fx(cur,jobs);
        int incl = jobs[cur][2] + (next == -1?0:maxPro(next,jobs));
        int excl = maxPro(cur+1,jobs);
        
        return memo[cur] = max(incl,excl);
    }
    
    int fx(int cur,vector<vector<int>>& jobs)
    {
        for(int next = cur+1;next<jobs.size();next++){
            if(jobs[next][0] >= jobs[cur][1])
                    return next;        
                }
        return -1;
    }
    
    //Bottom-Up solution:
    
     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i=0;i<profit.size();i++)
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        
        sort(jobs.begin(),jobs.end());
         
         vector<int>dp(jobs.size(),0);
         dp.back() = jobs.back()[2];
        for(int cur = jobs.size()-2;cur>=0;cur--)
        {
            int next = fx(cur,jobs);
            dp[cur] = max((jobs[cur][2] + (next == -1?0:dp[next])),dp[cur+1]); 
        }
        return dp[0];
     }
};