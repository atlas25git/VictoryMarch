class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        //Our idea basically here is that we need to have
        //directions to move in one while increasing array and the 
        //other decreasing
        //this could be done using i=n,j=0 or i=0,j=m
        //O(R+C) solution
        int i=n-1,j=0;
        while(i>=0 && j<m)
        {
            if(matrix[i][j] == x)
                return true;
            else if(matrix[i][j] < x)
                j++;
            else i--;
        }
        return false;
    }
};