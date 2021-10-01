bool isSafe(vector<int> maze[],int i,int j,int n)
{
    if(i<n && i>-1 && j<n && j>-1 && maze[i][j]>0)
        return true;
    return false;
}


bool util(vector<int> maze[],vector<int> sol[],int n,int i,int j)
{
    if(i==n-1 && j==n-1)
        {
            sol[i][j]=1;
            return true;
        }
    if(isSafe(maze,i,j,n))
    {
        sol[i][j]=1;
        for(int x=1;x<=maze[i][j];x++)
        {    
            if(util(maze,sol,n,i,j+x))
                return true;
            if(util(maze,sol,n,i+x,j))
                return true;
        }
        sol[i][j]=0;
        return false;
    }
    return false;
}


//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
void solve(int N, vector<int> maze[]) 
{
    vector<int>sol[N];
    for(int i=0;i<N;i++)
        sol[i]=vector<int>(N);
    if(util(maze,sol,N,0,0))
        print(N,sol);
    else cout<<"-1"<<endl;
    
}