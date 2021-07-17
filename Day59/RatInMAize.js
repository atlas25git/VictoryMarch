bool isSafe(int a, int b, int n, vector<int> maze[])
{
    //the safe condition is when a, b is in bounds and matrix value != 0.
    if (a >= 0 && a < n && b >= 0 && b < n && maze[a][b] != 0) 
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
        for (int i = 1; i <= maze[a][b] && i < n; i++)
        {
            if (solveMaze(a, b + i, n, maze, sol) == true)
            return true;
            if (solveMaze(a + i, b, n, maze, sol) == true)
            return true;
        }
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
        print(n, sol);
    }
}



// { Driver Code Starts
//Initial Template for javascript
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function print(n, sol) {
    let s = '';
    for (let i = 0; i < n; i++) {
        s = '';
        for (let j = 0; j < n; j++) {
            s += sol[i][j] + " ";
        }
        console.log(s);
    }
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let maze = [];
        for(let i=0; i<n; i++){
            let arr = [];
            let input_ar1 = readLine().split(' ').map(x=>parseInt(x));
            for(let j=0; j<n; j++)
                arr.push(input_ar1[j]);
            maze.push(arr);
        }
            
        let obj = new Solution();
        obj.solve(n, maze);
        
    }
}// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number} n
 * @param {number[][]} maze
*/

class Solution 
{   
    isSafe(maze,x,y,n)
    {
        if(x>=0 && x<n && y>=0 && y<n && maze[x][y]!=0)
            return true;
        return false;
    }
    
    util(maze,x,y,sol,n)
    {
        if(x==n-1 && y==n-1)
            {
                sol[x][y]=1;
                return true;
            }
        if(this.isSafe(maze,x,y,n))
        {
            sol[x][y]=1;
            for(let i=1;i<=maze[x][y] && i<n;i++)
                {
                    if(this.util(maze,x+i,y,sol,n))return true;
                    if(this.util(maze,x,y+i,sol,n))return true;
                }
            sol[x][y]=0;
            return false;
        }
        return false;
    }
    
    //Function to find the minimum number of Hops required for the rat to 
    //reach from the source block to the destination block.
    solve(n, maze)
    {
        let sol = new Array(n)
        for(let i=0;i<n;i++)
            sol[i]= new Array(n);
        for(let i=0;i<n;i++)
        {for(let j=0;j<n;j++)sol[i][j]=0;}
    
        if(this.util(maze,0,0,sol,n))
            print(n,sol);
        else console.log(-1);
    }
}