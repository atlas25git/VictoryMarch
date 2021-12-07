bool isValid(vector<int> maze[],int i,int j,int n)
{
    if(i<n && i>-1 && j<n && j>-1 && maze[i][j])return true;
    return false;
}

bool solve(vector<int> maze[], vector<int> S[],int i,int j,int n)
{
    if(i==n-1 && j==n-1)
    {
        S[i][j]=1;
        return true;
    }
    
    if(isValid(maze,i,j,n))
    {
        S[i][j] = 1;
        
        for(int x=1;x<=maze[i][j];x++)
        {
            if(solve(maze,S,i,j+x,n))return true;
            if(solve(maze,S,i+x,j,n))return true;
        }
        
        S[i][j] = 0;
    }
    return false;
}


//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
void solve(int N, vector<int> maze[]) 
{
    vector<int> S[N];
    for(int i=0;i<N;i++)
        S[i] = vector<int>(N,0);
    if(solve(maze,S,0,0,N))
        print(N,S);
    else cout<<-1<<"\n";
    
}
