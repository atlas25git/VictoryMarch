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
        this.nextRight = null;
    }
}

function buildTree(str){
   // Corner Case
   if(str.length === 0 || str[0] === "N")
       return null;

   // Create the root of the tree
   let root = new Node(parseInt(str[0]));

   // Push the root to the queue
   let queue = [];
   let start = 0;
   queue.push(root);

   // Starting from the second element
   let i = 1;
   while(queue.length !== start && i < str.length) {

       // Get and remove the front of the queue
       let currNode = queue[start];
       start++;

       // Get the current node's value from the string
       let currVal = str[i];

       // If the left child is not null
       if(currVal !== "N") {

           // Create the left child for the current node
           currNode.left = new Node(parseInt(currVal));

           // Push it to the queue
           queue.push(currNode.left);
       }

       // For the right child
       i++;
       if(i >= str.length)
           break;
       currVal = str[i];

       // If the right child is not null
       if(currVal !== "N") {

           // Create the right child for the current node
           currNode.right = new Node(parseInt(currVal));

           // Push it to the queue
           queue.push(currNode.right);
       }
       i++;
   }

   return root;
}

function printSpecial(root, res)
{
   if (root === null)
     return;

   let next_root = null;

   while (root !== null)
   {
      res.push(root.data);

      if( root.left && (!next_root) )
        next_root = root.left;
      else if( root.right && (!next_root)  )
        next_root = root.right;

      root = root.nextRight;
   }
   
   printSpecial(next_root, res);
}

function inorderUtil(root, res){
    if (root === null)
        return;
    inorderUtil(root.left, res);
    res.push(root.data);
    inorderUtil(root.right, res);
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let input_ar1 = readLine().split(' ');
        let root = buildTree(input_ar1);
        let obj = new Solution();
        obj.connect(root); 
        let res = [];
        printSpecial(root, res);
        let s = '';
        for(let i=0; i<res.length; i++){
            s += res[i] +" ";
        }
        console.log(s);
        res = [];
        inorderUtil(root, res); 
        s = '';
        for(let i=0; i<res.length; i++){
            s += res[i] +" ";
        }
        console.log(s);
    }
}// } Driver Code Ends


//User function Template for javascript

/**
 * @param {Node} p
*/

/*
class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
        this.nextRight = null;
    }
}
*/

class Solution 
{
    //Function to connect nodes at same level.
    connect(p)
    {
        //here our approach is to do a level order traversal while maintaining
        //particular level's end,
        //while inserting nodes at a particulr level we also keep count of the ones int
        //the corressponding level
        //for first it'll be root only
        //and a prev for storing the prev node in a level.
        //now if the prev node is not set then it means we are at the level start
        //hence we'll put it equal to our curr.
        //in any other case we put our prev to curr root.
        
        let q = [];
        q.push(p);
        let end=p,nxtEnd=null,prev=null,curr=null;
        while(q.length)
        {
            curr = q[0];
            q.shift();
            
            if(curr.left)
            {
                q.push(curr.left);
                nxtEnd = curr.left;
            }
            if(curr.right)
            {
                q.push(curr.right);
                nxtEnd = curr.right;
            }
            
            if(prev)prev.nextRight = curr;
            prev = curr;
            
            if(curr == end)
            {
                curr.nextRight = null;
                end = nxtEnd;
                prev = null;
            }
        }
        
    }
}