class Solution 
{
    public:
    
    bool empty(int grid[N][N],int& row, int& col)
    {
        for(row = 0;row<N;row++)
        {
            for(col=0;col<N;col++)
            {
                if(grid[row][col] == 0)return true;
            }
        }
        return false;
    }
    
    bool Srow(int grid[N][N],int row,int i)
    {
        for(int col=0;col<N;col++)
        {
            if(grid[row][col] == i)
                return true;
        }
        return false;
    }
    
    bool Scol(int grid[N][N],int col,int i)
    {
        for(int row=0;row<N;row++)
        {
            if(grid[row][col] == i)
                return true;
        }
        return false;
    }
    
    bool Sbox(int grid[N][N],int Sr,int Sc,int i1)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(grid[Sr+i][Sc+j] == i1)
                    return true;
        
        return false;
    }
    bool isSafe(int grid[N][N], int row, int col,int i)
    {
        return !Srow(grid,row,i)
                && !Scol(grid,col,i)
                && !Sbox(grid,row-row%3,col-col%3,i);
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    {   
        //finding coordinates to first missing number
        int row,col;
        
        if(!empty(grid,row,col))return true;
        
        for(int i=1;i<=N;i++)
        {
            if(isSafe(grid,row,col,i))
            {
                grid[row][col] = i;
                if(SolveSudoku(grid))return true;
                grid[row][col] = 0;
            }
        }
        
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cout<<grid[i][j]<<" ";
    }
};