class Solution
{
    public:
    //Function to return kth largest element from an array.
    int KthLargest(int arr[], int n, int k) {
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(-arr[i]);
            if(pq.size()>k)
                pq.pop();
        }
        
        //while(pq.size()>1)pq.pop();
        return -pq.top();
    }
};
