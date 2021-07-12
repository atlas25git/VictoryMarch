class Solution
{   
    public:
    //Function to reverse the columns of a matrix.
    void reverseCol(int n, int m, int matrix[][m])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m / 2; j++)
		{
			//swapping the elements (element at 1st column with element
			//at last column, element at 2nd column with element at
			//second last column and so on).
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][m - j - 1];
			matrix[i][m - j - 1] = temp;
		}
}
}