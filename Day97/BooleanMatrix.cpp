class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int>rows(r,0);
        vector<int>cols(c,0);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(matrix[i][j])rows[i]=cols[j]=1;
                
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(rows[i]||cols[j])matrix[i][j]=1;
    }
};