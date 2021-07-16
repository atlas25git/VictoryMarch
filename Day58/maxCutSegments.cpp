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