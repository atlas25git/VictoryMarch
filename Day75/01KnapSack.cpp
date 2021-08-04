class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int i, w; 
       int K[n+1][W+1]; 
      
       //building table K[][] in bottom up manner.
       for (i = 0; i <= n; i++) 
       { 
           for (w = 0; w <= W; w++) 
           { 
                //base case  
                if (i==0 || w==0) 
                    K[i][w] = 0;
                
                //if weight of current item is more than Knapsack capacity W
                //then this item cannot be included in the optimal solution. 
                else if (wt[i-1] <= w) 
                    K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
                    
                //else updating K[i][w] as K[i-1][w].   
                else
                    K[i][w] = K[i-1][w]; 
           } 
       } 
       //returning the result.
       return K[n][W]; 
    }
};

