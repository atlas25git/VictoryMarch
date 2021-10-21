class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K)
    {
        vector <int> res;
        //implementing MinHeap using priority queue and 
        //storing first k elements in it.
        priority_queue<int, vector<int>, greater<int>> pq(arr, arr+K + 1); 
	
	    for(int i = K + 1; i<num; ++i)
	    {
	        //storing top element from priority queue in list and popping it.
	        res.push_back (pq.top ());
	        pq.pop();
	        
	        //pushing the current array element in priority queue.
	        pq.push(arr[i]);
	    }
	    
	    //using a loop till priority queue becomes empty.
	    while(!pq.empty())
	    {
	        //storing top element from priority queue in list and popping it.
	        res.push_back (pq.top ());
	        pq.pop();
	    }
	    //returning the list.
	    return res;
}
};