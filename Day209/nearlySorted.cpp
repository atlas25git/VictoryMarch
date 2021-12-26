class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K)
    {
        vector <int> res;
        priority_queue<int, vector<int>, greater<int>> pq(arr, arr+K + 1); 
	
	    for(int i = K + 1; i<num; ++i)
	    {
	        res.push_back (pq.top ());
	        pq.pop();
	        pq.push(arr[i]);
	    }
	    

	    while(!pq.empty())
	    {
	        res.push_back (pq.top ());
	        pq.pop();
	    }

	    return res;
}
};
