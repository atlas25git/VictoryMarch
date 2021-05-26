// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
    int countUtil(int *aux,int n,int v)
    {
        if(v==0)return 1;
        if(n==0)return 0;
        
        int res = countUtil(aux,n-1,v);
        if(v-aux[n-1]>=0) res += countUtil(aux,n,v-aux[n-1]);
        
        
        return res;
    }
    
    
    int countWaysRec(int n)
    {
        int aux[n];
        for(int i=0;i<n-1;i++)aux[i]=i+1;
        return countUtil(aux,n-1,n);//extra call was due to the fact that, question only asked for the cases
        //with more than 1 integers
        
    }
    
    
    int countWays(int n){
        long long dp[n+1];
        for(int i=0;i<=n;i++)dp[i]=0;
        dp[0]=1;//base case
        
        //we're creating the table where index i denotes value of given no,
        //and we fill it in the fashion of bottom up manner as in no of, iterations
        //starting from 1 to upto N 
        int mod = (int)(1e9+7);
        for(int i=1;i<n;i++){
            //for all the no till N,be made from [1,i)
            //elements
        
            for(int j=i;j<=n;j++)
                dp[j]=(dp[j]%mod+dp[j-i]%mod)%mod;
            
        }
        return dp[n]%mod;
    }
    
};

// { Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends