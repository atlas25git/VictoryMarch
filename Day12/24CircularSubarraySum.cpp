// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
        
        //we get two sums
        //once the subarray sum with norma kadane,
        //then total sum - min subarray
        //the max of both of these is our ans
        
        //normal
        int sum=0,sumF=0;int count=0,maxx=INT_MIN;
        for(int i=0;i<n;i++)arr[i]<0?count+=1:count+=0,maxx=max(maxx,arr[i]),sum+=arr[i],sumF=max(sum,sumF),(sum<0?sum=0:sum+=0);
        //cout<<sumF<<" ";return sumF;
        if(count == n)return maxx;
        //total sum
        int Tsum = 0;
        for(int i=0;i<n;i++)Tsum+=arr[i];
        
        //min subArray
        for(int i=0;i<n;i++)arr[i]=-arr[i];
        
        int sumM=0,sumMF=0;
        for(int i=0;i<n;i++)sumM+=arr[i],sumMF=max(sumM,sumMF),sumM<0?sumM=0:sumM+=0;
        Tsum+=sumMF;
        return max(sumF,Tsum);
        
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends