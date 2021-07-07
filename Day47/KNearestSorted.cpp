// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        priority_queue<int,vector<int>,greater<int>> pq;
        k++;
        vector<int> res;
        for(int i=0;i+k<=n;i+=k)
        {   
            int i1=0;
            int k1=k;
            while(k1--)
            {
                pq.push(arr[i+i1]);
                i1++;
            }
            k1=k;
            i1=0;
            while(k1--)
            {
                res.push_back(pq.top());
                pq.pop();
                i1++;
            }
            i1=0;
            while
            (pq.size()!=0)pq.pop();
        }
        priority_queue<int,vector<int>,greater<int>> pq1;
        int i=1;
        int left=n%k;
        //cout<<left<<"left\n";
        while(left--)
        {   
            //cout<<left<<" "<<arr[n-i]<<" \n";
            pq1.push(arr[n-i]);
            i++;
            
        }
        left=n%k;
        while(left--)
        {
            res.push_back(pq1.top());
            pq1.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends