class Solution{
	public:
	    int m;
        vector<vector<int>> dp;
		int nthStair(int n){
		    dp.resize(3,vector<int>(n+1,1e9));
		    m = 1e9+7;
		    return ways(n,2);
		 }
		 
		 int ways(int n,int k)
		 {      
		     if(k <= 0)return 0;
		     if(!n)return 1;
		     if(dp[k][n] != 1e9)return dp[k][n];
		     int inc=0,exc=0;
		     if(k<=n)
		        inc = ways(n-k,k);
		     exc = ways(n,k-1);
		     
            return dp[k][n] = (inc%m + exc%m)%m;
		 }
		    
};
