class Solution
{
    public:
    //Function to find the kth smallest element in the array.
    int kthSmallest(int arr[], int n, int k)
    {
        //we here are storing k smallest elements
        //out of them the top will be the kth smallest
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            {
                if(pq.size()==k)
                    {
                        if(pq.top()>arr[i])
                            pq.pop(),pq.push(arr[i]);
                    }
                    else pq.push(arr[i]);
            }
        return pq.top();
    }
};