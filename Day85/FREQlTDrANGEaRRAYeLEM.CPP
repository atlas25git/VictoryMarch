class Solution{
    public:

    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        //Decreasing all elements by 1 so that the elements
        //become in range from 0 to n-1.
    	for (int i = 0; i < N ; i++) 
    		arr[i] = arr[i]-1; 
    	sort(arr.begin(), arr.end());
    	int ind = N;
    	
    	for(int i = 0 ; i < N ; i++)
    	{
    	   if(arr[i] >= N)
    	   {
    	       if(ind == N)
    	           ind = i;
    	       arr[i] = 0;
    	   }
    	}
    	//Using every element arr[i] as index.	
        //Updating the array elements using mathematical formula
        //to find the frequencies of all elements from 1 to N.
    	for (int i = 0; i < ind ; i++) 
    	    //Adding n to element present at arr[i]%n to keep
    	    //track of count of occurrences of arr[i].
    		arr[arr[i]%N]//gives the original index value after n subsequent addn
                 = arr[arr[i]%N] + N; 
    
        //Calculating the frequency of each element.
    	for (int i = 0; i < N; i++) 
    	    //Finally dividing the array elements by n to find the frequency.
    		arr[i] = arr[i]/N;
    }

};