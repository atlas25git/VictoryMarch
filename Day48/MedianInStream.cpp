// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    double median=0;
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq1;
    //we want the min heap to store the latter part of the array
    //consisting of greater no.
    
    //Function to insert heap.
    void insertHeap(int &x)
    {   
        //3 Cases:
        //start with filling the first subset first.
        //if it is empty -> fill right in;
        //else if the element is greater than the greatest here, put it in the other subset
        //if x is smaller than the greatest element, put the greatest element in 2nd subset
        //and insert x in former.
        //else if 1st!empty and 1st's gr8st < x insert x in former subset.
        
        if(!pq.size())
            pq.push(x);
        else if(pq.top()<x)
            pq1.push(x);
        else if(pq1.empty())
        {
            pq1.push(pq.top());
            pq.pop();
            pq.push(x);
        }
        else pq.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {   //since we're not letting it go beyond 1 much as we're calling
        //this fn at every insertion call, thus only one use case is to pondered over.
        if(abs(pq.size()-pq1.size()) > 1)
        {
            if(pq.size()>pq1.size())
                {pq1.push(pq.top()), pq.pop();}
            else 
                {pq.push(pq1.top()),pq1.pop();}
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if( !((pq.size()+pq1.size())&1))
        {
            median = (pq.top() + pq1.top());
            median /=2;
        }
        else{
            if(pq1.empty())
            {
                median = pq.top();
            }
            else if(pq1.size()<pq.size())
                median = pq.top();
            else
                median = pq1.top();
        }
        return median;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends