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
       int min_i=0,max_i=n;
       int i,j,median;
       
       while(min_i<=max_i)
       {    //Calculating indices of corressponding medians,
            //ith and jth iindices are inclusie in their sets
            //2 sets being {i-1,j-1: i,j}
           i=(min_i+max_i)/2;
           j=(n+m+1)/2-i;
           //conditions on alternate min and max
           //arr[i]>=br[j-1]
           //checking for the alterntes coz the original arrays are sorted
           //hence already satisfy the criteria
           
           //Search condition only working on the corner cases
           //{i-1,i : j-1,j}
           //proponent is that our sets at i,j should be greater than the former
           //so wqe check for the condition on i using j-1 and j
           if(i<n && j>0 && brr[j-1]>arr[i])
                min_i=i+1;
            //brr[j]>=arr[i-1]
            else if(i>0 && j<m && brr[j]<arr[i-1])
                max_i=i-1;
                
            else
            {   //caculating medians on the assumption that the total
                //elements are odd
                //last element of the first half
                //the cases where we just have one element of contestant
                if(i==0)median = brr[j-1];
                
                //last element of the first half when elements in b's
                //first half happen to be zero
                else if(j==0)median = arr[i-1];
                
                //discerning the one which would be the last
                else median = max(arr[i-1],brr[j-1]);
                break;
            }
            
        
       }
       //calculating median
       if((n+m)%2==1)return (double)median;
       if(i==n) return (median + brr[j])/2.0;
       if(j==m) return (median + min(arr[i],brr[j]))/2.0;
       
       //calculating the next element, case of even total elements
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