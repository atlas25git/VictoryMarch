class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r1= matrix.size();
        int c = matrix[0].size();
        
        int l=0,r=c-1,u=0,d=r1-1;
        
        vector<int> res;
        
        while(u<=d && l<=r)
        {
            //top
            //l->r
            for(int i=l;i<=r;i++)
                res.push_back(matrix[u][i]);
            u++;
            
            //right col u to d
            for(int i=u;i<=d;i++)
                res.push_back(matrix[i][r]);
            r--;
            
            //here we've introduced new checks as these are the stages of program when already some
            //updation has been done to the params, and hence now checking it again, for the intial
            //part of code while loop itself checks for these conditions.
            //r to l down
            if(u<=d)
            {
                for(int i=r;i>=l;i--)
                    res.push_back(matrix[d][i]);
                    d--;
            }
            //d to u left  most
            if(l<=r)
            {
                for(int i=d;i>=u;i--)
                    res.push_back(matrix[i][l]);
                l++;
            }
        }
            
        return res;
    }
};