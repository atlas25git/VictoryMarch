class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>cuts = {x,y,z};
        //the case of multiple occr of coins would be handled by
        //the equality condn in max
        vector<int> dp(n+1,INT_MIN);
        
        dp[0]=0;
        
        for(int i=0;i<cuts.size();i++)
            for(int j=1;j<=n;j++)
                if(cuts[i]<=j && (dp[j-cuts[i]]!=INT_MIN))
                    dp[j] = max(dp[j-cuts[i]]+1,dp[j]);
        
        return dp[n]==INT_MIN?0:dp[n];
    }
};

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //basically it's just coin change problem with max version of coins
        vector<int> dp(n+1,INT_MIN);
        vector<int> cuts = {x,y,z};
        
        //base case
        dp[0]=0;
        
        for(int i=0;i<3;i++)
            for(int j=1;j<=n;j++)
                if(cuts[i]<=j && dp[j-cuts[i]]!=INT_MIN)
                    dp[j] = max(dp[j-cuts[i]]+1,dp[j]);
        return dp[n]==INT_MIN?0:dp[n];
    }
};

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //storing the cut sizes
        int cuts[3];
        cuts[0]=x,cuts[1]=y,cuts[2]=z;
        
        //out dp[i] will contain the max cuts out of given cut segs
        //for a len of i
        
        int dp[n+1]={0};//0 states that no cuts possible
        
        //filling the array
        for(int i=0;i<3;i++)
            for(int j=1;j<=n;j++)//0 is not a signigicant len in parlance of question
                if(cuts[i]==j ||
                                (j>cuts[i]
                                        && dp[j-cuts[i]]>0) 
                                            //this here ensures that for the remaininng 
                                            //len there are cuts available, that it is 
                                            //bigger than the smaller 
                                            //cut seg, as here the segs are not sorted
                                )
                    dp[j]=max(dp[j-cuts[i]]+1,dp[j]);
        return dp[n];
            
    }
};