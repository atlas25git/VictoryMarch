class Solution 
{
    //Function to return the adjacency list for each vertex.
    printGraph(V, adj)
    {
        let ans = new Array(V);
        
        //iterating over each vertex.
  		for(let i=0;i<V;i++)
  		{
  		    ans[i] = new Array();
  		    
  		    //pushing the vertex at ith index and all the 
  		    //nodes connected to it in the output list.
  		    ans[i].push(i)
  			for(let j=0;j<adj[i].length;j++){
  				ans[i].push(adj[i][j]);
  			}
  		}
  		//returning the list.
  		return ans;
    }
}