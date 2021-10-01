
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
        
    	vector<vector<int>> result;
    	set<int>s(A.begin(),A.end());
    	vector<int> current, C(s.size());
    	
    	copy(s.begin(),s.end(),C.begin());
    	int i,j;
    	
    	combinationSumUtil(C, B, result, current,0);
    	
    	//returning the result.
    	return result;
    }
};