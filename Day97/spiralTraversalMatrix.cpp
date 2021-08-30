class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int row, int col) 
    {
        vector<int> ans;
        int l=0,r=col-1,u=0,d=row-1;
        while(l<=r && u<=d)
        {
            for(int i=l;i<=r;i++)ans.push_back(m[u][i]);u++;
            for(int i=u;i<=d;i++)ans.push_back(m[i][r]);r--;
            if(u<=d)for(int i=r;i>=l;i--)ans.push_back(m[d][i]);d--;
            if(l<=r)for(int i=d;i>=u;i--)ans.push_back(m[i][l]);l++;
        }
        return ans;
    }
};

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r1, int c) 
    {
        vector<int> ans;
        int l=0,u=0,r=c-1,d=r1-1;
        
        while(l<=r && u<=d)
        {
            //1> L to R
            for(int i=l;i<=r;i++)
                ans.push_back(matrix[u][i]);
            u++;//excluding the current row
            
            //2:u TO d
            for(int i=u;i<=d;i++)
                ans.push_back(matrix[i][r]);
            r--;//excluding curr col
            
            //r to l
            if(u<=d)
            {
                for(int i=r;i>=l;i--)
                    ans.push_back(matrix[d][i]);
                d--;
            }
            
            if(l<=r)
            {
                for(int i=d;i>=u;i--)
                    ans.push_back(matrix[i][l]);
                l++;
            }
        }
        return ans;
    }
};