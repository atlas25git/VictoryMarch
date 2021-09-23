class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        transpose(matrix);
        colSwap(matrix);
    } 
    void transpose(vector<vector<int>>&m)
    {
        for(int i=0;i<m.size();i++)
            for(int j=i;j<m[0].size();j++)
                swap(m[i][j],m[j][i]);
    }
    
    void colSwap(vector<vector<int>>& m)
    {
        for(int i=0;i<m[0].size();i++)
            {
                int k=0,j=m.size()-1;
                while(k<j)
                {
                    swap(m[k++][i],m[j--][i]);
                }
            }
    }
};