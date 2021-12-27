class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //All rotations are composite reflections
        //Here as per our observations line of symmetry for such
        //reflections happen to be diagoanl and vertical
        //diagonal
        transpose(matrix);
        //vertical
        reflect(matrix);
    }
    
    void transpose(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
    }
    
    void reflect(vector<vector<int>>& matrix)
    {
        for(auto &x : matrix)
        {
                reverse(x.begin(),x.end());
        }
    }
};