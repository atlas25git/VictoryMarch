class Solution
{
    public:
    void AllSubsetsHelper(vector<int> A, int index, int n, vector<int> current,
    vector<vector<int> > &result)
    {

        if(index >= n){
            result.push_back(current);
            return;
        }
        
        int curIndex=index+1;

        while(curIndex < n && A[curIndex] == A[index]){
            curIndex++;
        }
        
        int count = curIndex - index;
        

        for(int i=0;i<=count;i++)
        {
            for(int j=0;j<i;j++){
                current.push_back(A[index]);
            }
            AllSubsetsHelper(A, curIndex, n, current, result);
            
            for(int j=0;j<i;j++)
            {
                current.pop_back();
            }
        }
    }
 
    vector<vector<int> > AllSubsets(vector<int> A, int n)
    {
        vector<vector<int> > result;
        vector<int> current;
        sort(A.begin(),A.end());
        AllSubsetsHelper(A, 0, n, current, result);       
        sort(result.begin(),result.end());
        return result;
    }
};