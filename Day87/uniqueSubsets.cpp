class Solution
{
    public:
    
    void asu(vector<int>& arr,int sz,int ind,vector<vector<int>>& res,vector<int> curr)
    {
        if(ind>=sz)
            {
                res.push_back(curr);
                return;
            }
            
        //discerning the frequency of curr element
        int count=1;
        for(int i=ind+1;i<sz;i++)
            if(arr[ind] == arr[i])count++;
        
        //choose vs not choose
        for(int i=0;i<=count;i++)
            {
            for(int j=0;j<i;j++)curr.push_back(arr[ind]);
                //remember we need to skip all the repeating occr.
                asu(arr,sz,ind+count,res,curr);    
           
            for(int j=0;j<i;j++)curr.pop_back();
            }
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        //classic choose vs not choose, just that here we've got
        //couple of more options as well
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> curr;
        asu(arr,n,0,res,curr);
        sort(res.begin(),res.end());
        return res;
    }
};


class Solution
{
    public:
    void AllSubsetsHelper(vector<int> A, int index, int n, vector<int> current,
    vector<vector<int> > &result)
    {
        //if all elements are iterated then we store current vector in result.
        if(index >= n){
            result.push_back(current);
            return;
        }
        
        int curIndex=index+1;
        //checking for duplicate elements.
        while(curIndex < n && A[curIndex] == A[index]){
            curIndex++;
        }
        
        int count = curIndex - index;
        
        //inserting all the subsets in current.
        for(int i=0;i<=count;i++)
        {
            for(int j=0;j<i;j++){
                current.push_back(A[index]);
            }
            //calling function recursively for adding further subsets.
            AllSubsetsHelper(A, curIndex, n, current, result);
            
            for(int j=0;j<i;j++)
            {
                //backtracking to exclude current combinations and 
                //include further combinations.
                current.pop_back();
            }
        }
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> A, int n)
    {
        vector<vector<int> > result;
        vector<int> current;
        sort(A.begin(),A.end());
        AllSubsetsHelper(A, 0, n, current, result);    
        
        //sorting for ascending output.
        sort(result.begin(),result.end());
        
        //returning the result.
        return result;
    }
};