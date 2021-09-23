class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> rs(n,0);
        vector<int> cs(n,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                rs[i]+=matrix[i][j],
                cs[j]+=matrix[i][j];
        
        int ms=0;
        for(int i=0;i<n;i++)
            ms=max(ms,rs[i]),
            ms=max(ms,cs[i]);
        int c=0;
        for(int i=0,j=0;i<n && j<n;)
        {   
            //min df added to mat(i,j) would fix one r/c
            //this step ensures minimum operation condn
            int df = min(ms-rs[i],ms-cs[j]);
            matrix[i][j] += df;
            c+=df;
            rs[i]+=df;
            cs[j]+=df;
            if(rs[i]==ms)i++;
            if(cs[j]==ms)j++;
        }
        return c;
    } 
};