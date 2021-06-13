class Solution{
  public:
    //Function to merge two sorted list into one sorted list.
    Node* SortedMerge(Node* a, Node* b)
    {
    	Node* result = NULL;
    
    	//base cases when either of two lists is null.
    	if (a == NULL)
    		return (b);
    	else if(b == NULL)
    		return (a);
    
        //comparing data in both lists and storing the smaller in result and
        //recursively calling the SortedMerge function for next node in result.
    	if(a->data <= b->data)
    	{
    		result = a;
    		result->next = SortedMerge(a->next, b);
    	}
    	else
    	{
    		result = b;
    		result->next = SortedMerge(a, b->next);
    	}
        //returning the resultant list.
    	return result;
    }
    
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node* arr[], int K)
    {
        int N = K;
        int last=N-1; 
    	while (last != 0)
    	{
    		int i = 0, j = last;
    		while (i < j)
    		{
    			//calling SortedMerge function to merge two different list into
    			//one list which has sorted elements.
    			arr[i] = SortedMerge(arr[i], arr[j]);
    
    			//going for the next pair of lists.
    			i++, j--;
    
    			//if all pairs are merged, we update the last.
    			if (i >= j)
    				last = j;
    		}
    	}
        //returning the merged list.
    	return arr[0];
    }
};