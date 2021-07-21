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
        this.next = null;
    }
}

class TreeNode{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function push(head_ref, new_data) {
    let new_node = new Node(new_data);
    new_node.next = head_ref;
    head_ref = new_node;
    return head_ref;
}

function reverses(head) {
    let prev = null;
    let cur = head;
    let nxt;
    while (cur !== null) {
        nxt = cur.next;
        cur.next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
    return head;
}

function lvl(r) {
    if (r === null) return;
    let q = [];
    let start_q = 0;
    q.push(r);
    let s = '';
    while (q.length !== start_q) {
        let j = q[start_q];
        s += j.data + " ";
        start_q++;
        if (j.left) q.push(j.left);
        if (j.right) q.push(j.right);
    }
    console.log(s);
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let input_ar1 = readLine().split(' ').map(x=>parseInt(x));
        let head = null;
        for(let i=0;i<n;i++){
            head = push(head, input_ar1[i]);
        }
        head = reverses(head);
        let obj = new Solution();
        let root = obj.convert(head); 
        if(root === null){
            console.log("-1");
        }
        lvl(root);
    }
}// } Driver Code Ends


//User function Template for javascript

/**
 * @param {Node} head
 * @returns {TreeNode}
*/

/*
class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class TreeNode{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    //Function to make binary tree from linked list.
    convert(head)
    {
        //here basically the idea is to iterate on the linked list and
        //storing in a queue, it's top's children will be pointed by our curr itr
        //and thus storing the part in each level order traversal
        
        let root = new TreeNode(head.data);
        head = head.next;
        let q = [];
        q.push(root);
        
        while(head)
        {
            let c = q[0];
            q.shift();
            
            let l = new TreeNode();
            let r = null;
            
            l.data = head.data;
            head = head.next;
            q.push(l);
            
            if(head)
            {
                r = new TreeNode(head.data);
                head = head.next;
                q.push(r);
            }
            
            c.left = l?l:null;
            c.right = r?r:null;
        }
        
        
        return root;
    }
}