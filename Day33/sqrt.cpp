// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
  
    long long int sqrtR(long long int x,long long int l,long long int h,long long int& ans)
    {   if(h<l)return ans;
        long long int mid = l + (h-l)/2;

        if(mid*mid == x)return mid;
        else if(mid*mid<x){ans=mid,sqrtR(x,mid+1,h,ans);}
        else sqrtR(x,l,mid-1,ans);
    }
    
  
    long long int floorSqrt(long long int x) 
    {
       if(x==0 || x==1)return x;
       long long int h=x,l=1,ans;
       return sqrtR(x,l,h,ans);
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends