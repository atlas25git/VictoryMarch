class Solution {
public:
    vector<int> dp;
    int jump(vector<int>& nums) {
        dp.resize(nums.size(),INT_MAX);
        
        dp[0] = 0;
        
        for(int i=1;i<nums.size();i++)
            for(int j=0;j<i;j++)
                if(nums[j] + j>= i && dp[j]!=INT_MAX)
                {
                    dp[i] = min(dp[i],dp[j] + 1);
                }
        
        return dp[nums.size()-1];//jmpRec(nums,nums.size()-1);
    }
    
//     int jmpRec(vector<int>& nums,int n)
//     {
        
//         if(n==0)return 0;
//         if(memo[n] != INT_MAX)return memo[n];
        
//         int res = INT_MAX;
//         for(int i=0; i<=n-1;i++)
//         {
//             if(nums[i] + i >= n )
//             {
//                 int sr = jmpRec(nums,i);
//                 if(sr!=INT_MAX)
//                     res = min(res,sr+1);
//             }
//         }
//         return memo[n] = res;
//     }
};