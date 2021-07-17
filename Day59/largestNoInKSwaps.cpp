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
        let k = parseInt(readLine());
        let str = readLine();
        let obj = new Solution();
        console.log(obj.findMaximumNum(str, k));
        
    }
}// } Driver Code Ends


//User function Template for javascript

/**
 * @param {string} str
 * @param {number} k
 * @returns {string}
*/

class Solution 
{
    constructor()
    {
        this.str = [];
        this.res = [];
    }
    
    match()
    {
        for(let i=0; i<this.str.length; i++)
        {
            if( this.res[i] > this.str[i] )
                return;
            
            //if str[i] is greater, we update res as str or store
            //the larger value in res.
            if( this.res[i] < this.str[i] )
            {
                for(let j=0; j<this.str.length; j++)
                    this.res[j] = this.str[j];
                return;
            }
        }
    }
    
    cmp(a,b)
    {
        for(let i =0;i<a.length;i++)
        {
                if(b[i]>a[i])return;
                if(b[i]<a[i])
                {    
                    this.res=[...this.str];
                    return;
                    // for(let j=0;j<a.length;j++)
                    // b[j]=a[j];
                    // return;
                }
        }
    }
    
    setDigit(index,k)
    {
        //base case
        if(!k || index === this.str.length-1)
            {   
                
                this.cmp(this.str,this.res);
                return;
            }
        
        let maxD = 0;
        for(let i=index;i<this.str.length;i++)
            maxD = Math.max(maxD, this.str[i].charCodeAt(0)-48);
            
        if(this.str[index].charCodeAt(0)-48 == maxD)
            {
                this.setDigit(index+1,k);
                return;
            }
        for(let i=index+1;i<this.str.length;i++)
        {
            if(this.str[i].charCodeAt(0)-48 == maxD)
              {  
                let temp2 = this.str[index];
                this.str[index] = this.str[i];
                this.str[i] = temp2;
                
                this.setDigit(index+1,k-1);
                
                temp2 = this.str[index];
                this.str[index] = this.str[i];
                this.str[i] = temp2;
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    findMaximumNum(str, k)
    {
        //converting to char arrays
        this.res = str.split('');
        this.str = str.split('');
        this.setDigit(0,k);
        return this.res.join("");
    }
}