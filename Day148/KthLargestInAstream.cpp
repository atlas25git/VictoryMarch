class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
    	priority_queue<int> pq;
    	for(int i=0;i<n;i++)
    	{
    	    if(pq.size()<k)pq.push(-arr[i]);
    	    else
    	    {
    	        if(-pq.top() < arr[i])
    	            pq.pop(),
    	            pq.push(-arr[i]);
    	    }
    	    if(pq.size()<k)cout<<-1<<" ";
    	    else cout<<-pq.top()<<" ";
    	}
    }
};