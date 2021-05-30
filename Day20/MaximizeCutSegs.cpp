// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int arr[3];
        arr[0]=x;
        arr[1]=y;
        arr[2]=z;
        
        //creating a dp[] array and initializing all values with 0.
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        for(int j=0;j<3;j++)
        {
            for(int i=1;i<=n;i++)
            {
                
                if(i==arr[j] or (i>arr[j] and dp[i-arr[j]]>0))
                    dp[i]=max(dp[i-arr[j]]+1,dp[i]);
                }
        }
        //returning the result.
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends