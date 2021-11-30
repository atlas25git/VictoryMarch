class Solution {
    vector<int> nums;
    vector<int> dp;
public:
    int jump(vector<int>& n) {
        
        
        swap(nums,n);
        return noDp();
        
        dp.resize(nums.size(),INT_MAX);
        dp[0]=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=i-1;j>-1;j--)
                if(nums[j] + j>=i)
                    dp[i] = min(dp[i],dp[j]+1);
        }
        
        
        return dp.back();//steps(nums.size()-1);
    }
    
    
    int noDp()
    {
        if(nums.size()<=1)return 0;
        if(!nums[0])return -1;
        
        int maxRange = nums[0];
        int steps = nums[0];
        int j = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(i == nums.size()-1)
                    return j;
            maxRange = max(maxRange,nums[i]+i);
            steps--;
            if(!steps)
            {
                if(maxRange<=i)return -1;
                j++;
                steps = maxRange - i;
            }
        }
        return -1;
    }
    
    int steps(int step)
    {
        if(step == 0)return 0;
        if(dp[step]!=-1)return dp[step];
        
        int res = INT_MAX;
        for(int i=step-1;i>-1;i--)
        {
            if(i+nums[i]>=step)
                {
                    int subRes = steps(i);
                    if(subRes!=INT_MAX)
                        res = min(res,subRes+1);
                }
        }
        return dp[step] = res;
    }
};