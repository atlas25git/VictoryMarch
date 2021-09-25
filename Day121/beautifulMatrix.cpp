class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        //We will maintin row wise and col wise sum
        //then we'll store the max of such sums
        //now we'll iterate the matrix for any i,j starting with {0,0}
        //we'll take the min dif from max values of rs[i] and cs[i] with rs[i],cs[j];
        //and we'll perform the min oprns and move fwd
        
        vector<int> cs(n),rs(n);
        
        int ms=INT_MIN;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                rs[i]+=matrix[i][j],
                cs[j]+=matrix[i][j],
                ms = max({ms,rs[i],cs[j]});
        // cout<<ms<<endl;
        int moves = 0;
        
        for(int i=0,j=0;i<n && j<n;)
        {
            int df = min(ms-rs[i],ms-cs[j]);
            matrix[i][j] += df;
            cs[j] += df;
            rs[i] += df;
            moves += df;
            if(rs[i] == ms)i++;
            if(cs[j] == ms)j++;
        }
        
        return moves;
        
    } 
};