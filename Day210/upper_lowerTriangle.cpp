class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        int lower_sum = 0;
        int upper_sum = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    upper_sum+=matrix[i][j],
                    lower_sum += matrix[i][j];
                else if(i<j)
                    upper_sum+=matrix[i][j];
                else
                    lower_sum += matrix[i][j];
            }
        return vector<int>({upper_sum,lower_sum});
    }
};
