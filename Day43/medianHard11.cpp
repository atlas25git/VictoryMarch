// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {   
        //using 1 based index so as we get the latter part's starting index
        //in both the arrays, therefore in the case of odd elements 
        //median would lie at n-1
        int minI=0,maxI=n;
        int i,j,median;
        //our i & j will be adjacent in the combined array
        while(minI<=maxI)
        {
            i=(minI+maxI)/2;
            j=(n+m+1)/2 - i;
            
            if(j<m && i>0 && brr[j]<arr[i-1])
                    maxI=i-1;
            else if(j>0&&i<n && brr[j-1]>arr[i])
                   minI=i+1;
        
            else
            {   
                if(i==0)
                    median = brr[j-1];
                if(j==0)
                    median = arr[i-1];
                else median = max(arr[i-1],brr[j-1]);  
                break;
            }
            
        }
        //calculating median
        if((n+m)&1) return (double)median;
        if(i==n)return (median + brr[j])/2.0;
        if(j==m)return (median + arr[i])/2.0;
        
        return (median + min(arr[i],brr[j]))/2.0;
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}  // } Driver Code Ends