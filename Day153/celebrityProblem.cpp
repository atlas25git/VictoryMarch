class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int indegree[n] = {0},outdegree[n] = {0};
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                indegree[j] += M[i][j];
                outdegree[i] += M[i][j];
            }
        
        for(int i=0;i<n;i++)
        if(n!=0 && indegree[i] == n-1 && outdegree[i] == 0)
            return i;
    
        return -1;
    }
};