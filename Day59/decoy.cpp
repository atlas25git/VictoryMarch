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





//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
bool isSafe(int a, int b, int n, vector<int> maze[])
{
    //the safe condition is when a, b is in bounds and matrix value != 0.
    if (a >= 0 && a < n && b >= 0 && b < n && maze[a][b] != 1) 
        return true;
    return false;
}

bool solveMaze(int a, int b, int n, vector<int> maze[], vector<int> sol[])
{
    //base case
    if (a == n - 1 && b == n - 1) 
    {
        //marking (a,b) as part of solution.
        sol[a][b] = 1;
        return true;
    }

    if (isSafe(a, b, n, maze) == true) 
    {
        // marking (a,b) as part of solution.
        sol[a][b] = 1;

        //checking for further path.
        //for (int i = 1; i <= maze[a][b] && i < n; i++)
        //{
            int i=1;
            if (solveMaze(a, b + i, n, maze, sol) == true)
            return true;
            if (solveMaze(a + i, b, n, maze, sol) == true)
            return true;
        //}
        //if no possible path is present in the direction then we mark (a,b) 
        //as not a part of solution and doing backtracking, return false.
        sol[a][b] = 0;
        return false;
    }
    //if not safe, we return false.
    return false;
}

//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
void solve(int n, vector<int> maze[])
{
    vector<int> sol[n];
    for (int i = 0; i < n; i++) sol[i].assign(n, 0);
    
    //if no path found,we print -1.
    if (solveMaze(0, 0, n, maze, sol) == false)
        cout << "-1" << endl;
    else
    {
        //if path found, we call the function to print the result.
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                cout<<sol[i][j]<<" ";
                cout<<"\n";
            }
    }
}