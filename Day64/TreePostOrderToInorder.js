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

class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function preOrder(root, res){
    if (root === null)
        return;
    res.push(root.data);
    preOrder(root.left, res);
    preOrder(root.right, res);
}


function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let input_ar1 = readLine().split(' ').map(x=>parseInt(x));
        let input_ar2 = readLine().split(' ').map(x=>parseInt(x));
        let ino = [];
        let post = [];
        for(let i=0; i<n; i++){
            ino.push(input_ar1[i]);
            post.push(input_ar2[i]);
        }
        let obj = new Solution();
        let root = obj.buildTree(ino, post, n); 
        let res = [];
        preOrder(root, res); 
        let s = '';
        for(let i=0; i<res.length; i++){
            s += res[i] +" ";
        }
        console.log(s);
        
    }
}// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} ino
 * @param {number[]} post
 * @param {number} n
 * @returns {Node}
*/

/*
class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution 
{
    constructor(){
        this.index=0;
    }
    
    bT(ino,post,i,j)
    {   
        //This fn basically returns the built tree for this we take to markers
        //i and j denoting no of children for a given index's node.
        //if i==j we return the child,else we divide into sub Problems, and thus fill
        //node's right and left pointers and atlast return the node.
        
        if(i>j)return null;
        
        let tNode = new Node(post[this.index]);
        this.index--;
        
        if(i==j)return tNode;
        
        let inIndx = this.search(ino,i,j,tNode.data);
        
        //right before  the left becoz we are iterating from end of post order
        //hence right comes first than the left.
        tNode.right = this.bT(ino,post,inIndx+1,j);
        tNode.left = this.bT(ino,post,i,inIndx-1);
        
        return tNode;
    }
    
    search(ino,i,j,x)
    {
    
        for(let s = i;s<=j;s++)
            if(ino[s]==x)return s;
    }
    //Function to return a tree created from postorder and inoreder traversals.
    buildTree(ino, post, n)
    {
        this.index = n-1;
        
        return this.bT(ino,post,0,n-1);
    }
}