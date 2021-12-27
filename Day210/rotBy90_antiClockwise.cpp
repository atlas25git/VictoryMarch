class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        //reflection across
        //Diagonal los:
        transpose(matrix);
        //horizontal line of symmetry
        reflect(matrix);
    } 
    
    void transpose(vector<vector<int>> &mat)
    {
        //Intially in including all i,j pairs swap occrd twice,
        //Hence resulting in cancelling their individual effects.
        for(int i = 0;i<mat.size();i++)
            for(int j=i;j<mat[0].size();j++)
                swap(mat[i][j],mat[j][i]);
    }
    
    void reflect(vector<vector<int>>& mat)
    {
        for(int i=0;i<mat[0].size();i++)
            {
                int j=0,k=mat.size()-1;
                while(j<=k)
                {
                    swap(mat[j++][i],mat[k--][i]);
                }
            }
    }
};
