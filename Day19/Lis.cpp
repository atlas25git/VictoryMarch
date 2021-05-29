// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    //   int lis[n]={0};lis[0]=1;
    //   for(int i=1;i<n;i++)
    //   {
    //       lis[i]=1;
    //       for(int j=0;j<i;j++)
    //       if(a[j]<a[i])
    //       lis[i]=max(lis[i],lis[j]+1);
    //   }
       
    //   int res = lis[0];
    //   for(int i=1;i<n;i++)res=max(res,lis[i]);
    //   return res;
    // }
    
    int ceilIdx(int tail[], int l, int r, int key) 
        { 
            while (r > l) {         
                int m = l + (r - l) / 2; 
                if (tail[m] >= key) 
                    r = m; 
                else
                    l = m+1; 
            } 
      
            return r; 
        } 
  
    int longestSubsequence(int n,int arr[]) 
    { 
     
  
        int tail[n]; 
        int len =1; 
  
        tail[0] = arr[0]; 
        
        for (int i = 1; i < n; i++) {
            
            if(arr[i] > tail[len - 1])
            {
                tail[len] = arr[i];
                len++;
            }
            else{
                int c =upper_bound(tail,tail+len-1,arr[i])-tail;
                //int x =upper_bound(tail,tail+len-1,arr[i])-tail;
                //cout<<"c: "<<c<<"ub: "<<x<<endl;
                tail[c] = arr[i];
            }
        } 
        
        return len; 
    } 
    
    
    
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends