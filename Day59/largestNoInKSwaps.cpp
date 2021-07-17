    //Basically check for the base cases !k & count == strlen
    //discern the max available in the str[count,end]
    //if the index is same as counter of the max, then continue with k--
    //else run a loop from count+1 and when the index of max element is found
    //swap it with curr index, make a call with updated params.
    //backtrack by reswapping the elements after the call is over.

    //Back-end complete function Template for javascript

/**
 * @param {string} str
 * @param {number} k
 * @returns {string}
*/

class Solution
{
    
    constructor(){
        this.str = [];
        this.res = [];
    }
    
    //Function to compare two strings and updating res
    //which stores the string with larger number.
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
    
    //Function to set highest possible digits at given index.
    setDigit(index, k)
    {
        // base case
        if(k === 0 || index === this.str.length - 1)
        {
            this.match();
            return;
        }
        
        let maxDigit = 0;
        
        //finding maximum digit for placing at given index.
        for(let i=index; i<this.str.length; i++)
            maxDigit = Math.max( maxDigit, this.str[i].charCodeAt(0) - 48 );
        
        // swapping isn't needed in this case.
        if( this.str[index].charCodeAt(0) - 48 == maxDigit )
        {
            this.setDigit(index+1, k);
            return;
        }
        
        for(let i=index+1; i<this.str.length; i++)
        {
            // if max digit is found at current index.
            if( this.str[i].charCodeAt(0) - 48 == maxDigit )
            {
                //swapping to get the maximum digit at required index.
                let temp2 = this.str[index];
                this.str[index] = this.str[i];
                this.str[i] = temp2;
                
                //calling recursive function to set the next digit.
                this.setDigit(index+1, k-1);
                
                // backtracking
                temp2 = this.str[index];
                this.str[index] = this.str[i];
                this.str[i] = temp2;
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    findMaximumNum(str, k)
    {
        this.res = str.split('');
        this.str = str.split('');
        this.setDigit(0, k);
        
        //returning the result.
        return this.res.join("");
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
    
    setDigit(index,k)
    {
        //base case
        if(!k || index === this.str.length-1)
            return;
        
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