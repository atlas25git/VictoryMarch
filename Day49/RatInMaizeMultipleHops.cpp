// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends

bool isSafe(int a,int b,int n, vector<int> maze[])
{
    if(a>=0 && a<n && b>=0 && b<n && maze[a][b]!=0)
        return true;
    return false;
}

bool solve(vector<int> maze[],int n,vector<int> sol[],int a,int b)
{
        if(a==n-1 && b==n-1)
        {
            sol[a][b]=1;
            return true;
        }
        
        if(isSafe(a,b,n,maze))
        {
            sol[a][b]=1;
            for(int i=1;i<=maze[a][b] && i<n;i++)
            {
                if(solve(maze,n,sol,a,b+i))return true;
                if(solve(maze,n,sol,a+i,b))return true;
            }
            sol[a][b]=0;
            return false;
        }
        
        return false;
}



//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
void solve(int n, vector<int> maze[]) 
{
        vector<int> sol[n];
        for(int i=0;i<n;i++)
            sol[i].assign(n,0);
        if(!solve(maze,n,sol,0,0))
                cout<<-1<<endl;
        else print(n,sol);
}