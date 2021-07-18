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

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let input_ar1 = readLine().split(' ').map(x=>parseInt(x));
        let n = input_ar1[0];
        let m = input_ar1[1];
        let obj = new Solution();
        console.log(obj.solve(n, m));
        
    }
}// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number} n
 * @param {number} m
 * @returns {number}
*/

class Solution 
{
    //Function to find out the number of ways we can place a black and a 
    //white Knight on this chessboard such that they cannot attack each other.
    solve(n, m)
    {   let M = 1e9+7;
        let x = [1,1,2,2,-1,-1,-2,-2];
        let y = [2,-2,1,-1,2,-2,1,-1];
        let count=0;
        for(let i=0;i<n;i++)
            for(let j=0;j<m;j++)
                for(let k=0;k<8;k++)
                    {
                        let xc = i + x[k];
                        let yc = j + y[k];
                        
                        if(xc>=0 && yc>=0 && xc<n && yc<m)
                            count++;
                    }
        let total = n*m;
        total = (total*(total-1))%M;
        return (total+M-count)%M;
    }
}