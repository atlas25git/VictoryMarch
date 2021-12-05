class Solution
{   vector<int> dp;
    public:
    //Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int sizeOfArray)
    {   
        int c=0;
        int msf = INT_MIN;
        for_each(arr,arr+sizeOfArray,[&c,&msf](int a){if(a<0)c++;msf = max(msf,a);});
        if(c==sizeOfArray)return msf;
        dp.resize(sizeOfArray,-1);
        maxS(arr,sizeOfArray-1);
        return dp.back();
    }
    
    int maxS(int* arr,int n)
    {
        if(n == 0)return max(arr[0],0);
        if(n==1)return max(arr[1],max(arr[0],0));
        
        if(dp[n] != -1)return dp[n];
        int res = max({maxS(arr,n-1),arr[n] + maxS(arr,n-2)});
        return dp[n] = res;
    }
};