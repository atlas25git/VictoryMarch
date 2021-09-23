class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {   
        queue<pair<int,int>>q;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
            if(matrix[i][j]==1)
                    q.push({i,j});
        
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            tf(matrix,x.first,x.second);
        }
        
    }
    
    void tf(vector<vector<int>>& mt,int i,int j)
    {
        int r=mt.size(),c=mt[0].size();
        
        for(int k=0;k<c;k++)
            mt[i][k]=1;
        for(int k=0;k<r;k++)
            mt[k][j] = 1;
    }
};
