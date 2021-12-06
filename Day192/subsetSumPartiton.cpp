class Solution {
public:
    bool canPartition1(vector<int>& nums) {
        int sum=0;
        for(auto x: nums)sum+=x;
        if(sum&1)return false;
        
        vector<vector<bool>>dp(2,vector<bool>(sum+1,false));
        //now we'll see if we can fill up the knapsack with given elements
        //to a capacity of sum/2.
        for(int i=0;i<=nums.size();i++)
            for(int j=0;j<=sum;j++)
                if(!j)
                    dp[i%2][j]=true;
                else if(!i)
                    dp[i%2][j]=false;
                else if(nums[i-1]<=j)
                    //cases of excluding and including the items.
                    //we're checking for the sum j if it is possible
                    //to make a subset adding up to that value using
                    //i elements, case 1 being including i, hence we'll check the,
                    //state space for {i-1} elements and a sum of(j-[i'th] element).
                    //and case 2 being excluding i.
                    dp[i%2][j] = dp[(i+1)%2][j] || dp[(i+1)%2][j-nums[i-1]];
                else 
                    dp[i%2][j] = dp[(i+1)%2][j];                
        
        return dp[1][sum/2];
    }
    vector<vector<int>>memo;
    
    bool canPartition(vector<int>& nums){
        
        memo.resize(20001,vector<int>(201,0));
        int sum=0;
        for(auto x: nums)sum+=x;
        if(sum&1)return false;
        return fill(sum/2,nums,nums.size());
    }
    
    bool fill(int sum,vector<int>& nums,int n){
        if(sum == 0)
            return true;
        if(n<=0 || sum<0)
            return false;
        if(memo[sum][n])
            return memo[sum][n]==2?1:0;
        bool exc = fill(sum,nums,n-1);
        bool inc = fill(sum-nums[n-1],nums,n-1);
        
        int res = (exc || inc)?2:1;
        memo[sum][n] = res;
        return exc || inc;
    }
};