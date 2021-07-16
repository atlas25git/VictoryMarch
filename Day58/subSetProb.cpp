class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int ar[], int n) 
    {
        int sum = 0;
        int i, j;
    
        //storing sum of all elements.
        for (i = 0; i < n; i++) 
        sum += ar[i];
    
        //if the total sum is odd, returning false. 
        if (sum % 2 != 0) 
        return false;
    
        //the value of subset[i%2][j] will be true if there exists 
        //a subset of sum j in arr[0, 1, ...., i-1].
        bool subset[2][sum + 1];
    
       //iteratively build up a boolean array to mark the presence of
       //a subset with sum == j and comprising of a subset among the i elements
       
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=sum;j++)
           {
               //i=0, items zero
               if(i==0) subset[i%2][j]=false;
               //j=0 subset for sum=0
               else if(j==0) subset[i%2][j]=true;
               
               else if(ar[i-1]<=j)
                    subset[i%2][j]=subset[(i+1)%2][j-ar[i-1]] || subset[(i+1)%2][j];
                    
                else
                    subset[i%2][j]=subset[(i+1)%2][j];

           }
          
       }
        return subset[0][sum/2];
       
    }
};