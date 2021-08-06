// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int cs = 0;
        vector<int> res;
        int start=0,end=0;
        
        for(int i=0;i<n;i++)
        {
            cs += arr[i];
            if(cs>=s)
            {   end = i;
                
                while(cs>s && start <= end)
                    {
                        cs -= arr[start++];
                    }
                
                
                if(cs == s)
                {
                    res.push_back(start+1);
                    res.push_back(end+1);
                    break;            
                }  
            }
        }
        
        if(!res.size())res.push_back(-1);
        return res;
        
    }
    
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int last=0;
        int start=0;
        unsigned long long  currsum=0;
        bool flag=false;
        vector<int>res;
        
        //iterating over the array.
        for(int i=0;i<n;i++)
        {
            //storing sum upto current element.
            currsum += arr[i];
            
            //checking if current sum is greater than or equal to given number.
            if(currsum>=s)
            {
                last=i;
                //we start from starting index till current index and do the 
                //excluding part while s(given number) < currsum.
                while(s<currsum && start<last)
                {
                    //subtracting the element from left i.e., arr[start]
                    currsum -= arr[start];
                    ++start;
                }
                
                //now if current sum becomes equal to given number, we store 
                //the starting and ending index for tahe subarray.
                if(currsum==s)
                {
                    res.push_back(start + 1);
                    res.push_back(last + 1);
                    
                    //flag is set to true since subarray exists.
                    flag = true;
                    break;
                }
            }
        }
        //if no subarray is found, we store -1 in result.
        if(flag==false)
            res.push_back(-1);
            
        //returning the result.
        return res;    
    }
};



// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends