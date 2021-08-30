class Solution
{   
    public:     
    void transpose(vector<vector<int> >& matrix, int n) 
    { 
        for (int i = 0; i < n; i++) 
            for (int j = i+1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]); 
    } 
    void reverseColumns(vector<vector<int> >& arr, int n) 
    { 
        for (int i = 0; i < n; i++) 
            {   
                int j=0;int k=n-1;
                while(j<k)
                {
                    swap(arr[j][i],arr[k][i]);
                    j++,k--;
                }
            }
    } 
      
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        transpose(matrix, n); 
        reverseColumns(matrix, n); 
    } 
};