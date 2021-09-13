int minJumps(int arr[],int n)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
        dp[i] = INT_MAX;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j] + j >= i)
            {
                if(dp[j]!=INT_MAX)
                    dp[i] = min(dp[i],dp[j]+1);
            }
        }
    }
} 

class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
        
        //sanitation check
        if(n<=1)return 0;
        if(!arr[0]) return -1;
        
        //default case as we will start from first cell
        int maxRange = arr[0];
        int steps = arr[0];
        int j = 1;
        
        for(int i=1;i<n;i++)
        {
            if(i==n-1)return j;
            //in the forseeable range updating the max reachable
            //position by utilising 1 jump
            maxRange = max(maxRange,arr[i]+i);
            //The case of utilizing extra steps over the i+mR range are exploited here
            //as only when the remanant steps are nulled, the next jump from the local maxima
            //would be made.
            steps--;//checks if the avl domain has been checked completely
            if(!steps)
            {
                if(maxRange<=i)return -1;
                j++;//jump made
                steps = maxRange - i; 
            }
        }
        
        return -1;
        
    }
};