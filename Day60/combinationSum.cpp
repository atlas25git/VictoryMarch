class Solution  {
  public:
    void combinationSumUtil(vector<int> &A, int sum, 
    vector<vector<int> >&result, vector<int> current, int pos)
    {
        //pushing the combination in result if the sum becomes equal to 0.
    	if(sum==0){ 
    		result.push_back(current);
    		return;
    	}
    	//returning if conditions are out of bound.
    	if(sum<0 || pos>=A.size()) 
    		return; 
        
        //pushing to current for possible answer.
    	current.push_back(A[pos]); 
    	
    	//calling function recursively for further inclusions.
    	combinationSumUtil(A, sum-A[pos], result,  current, pos );
    	
    	//backtracking to remove already present number in combination
        //and provide space for further additions and possible answers.
    	current.pop_back(); 
    	
    	//calling function recursively to move to next index as all possible
    	//combination for current index have been done.
    	combinationSumUtil(A, sum, result,  current, pos+1 ); 
    	
    }
    
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B)
    {
        
        sort(A.begin(),A.end());
    	vector<vector<int> > result;
    	vector<int> current, C;
    	int i,j;
    	
    	//storing only distinct elements in list C.
    	for(i=0;i<A.size();i++)
    	{
    	    j=i+1;
    	    while(j<A.size()&&A[i]==A[j]){
    	        j++;
    	    }
    	    C.push_back(A[i]);
    	    i=j-1;
    	}
    	combinationSumUtil(C, B, result, current,0);
    	
    	//returning the result.
    	return result;
    }
};