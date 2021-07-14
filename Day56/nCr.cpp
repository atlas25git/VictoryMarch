// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends




class Solution
{
    public:
    const int p = 1e9+7;
    //Function to return nCr mod 10^9+7 for given n and r. 
    int nCrModp(int n, int r) 
    { 
      
      int pascal[r+1]={0};
      //since r is on 1 based index and we just need max of r elements
      //to get our ans for r.
      //baseCase:
      pascal[0]=1;
      for(int i=1;i<=n;i++)
      {//iterating through rows
       //for every row i, i cols are concerned
       //but we just need the intial r-1 for the n,rth
       for(int j=min(i,r);j>0;j--)
            pascal[j] = (pascal[j]%p + pascal[j-1]%p)%p;
          
      }
      return pascal[r];
    } 
};

// { Driver Code Starts.
// Driver program 
int main() 
{ 
  int t, n, r;
  
  //taking count of testcases
  cin >> t;
  
  while(t--){
      
      //taking n and r
      cin >> n >> r;
      Solution ob;
      //calling method nCrModp()
      cout << ob.nCrModp(n, r) << endl;
  }
  
  return 0; 
}
  // } Driver Code Ends