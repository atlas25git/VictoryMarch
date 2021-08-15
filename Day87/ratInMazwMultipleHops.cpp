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
                    if(this.util(maze,x,y+i,sol,n))return true;
                    if(this.util(maze,x+i,y,sol,n))return true;
                }
            //none gave us the destination route, hence backtracking and reverting
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
