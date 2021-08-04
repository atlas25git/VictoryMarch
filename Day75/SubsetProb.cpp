class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        //since we need to return if there exists a partition
        //such that the array could be divided into 2 subsets
        //hence we build up an array for total sum, and fill it 
        //incrementally if that instance's sum is present as a subset
        //thus we our dp[i][j], will return if a subset of sum j exists
        //in 0 to i-1 elemetns
        //and thus will return for sum/2;
        
        int sum=0;
        for(int i=0;i<n;i++)sum+=a[i];
        if(sum%2)return false;
        bool dp[2][sum+1];
        //since we'll need just one row preceeding in the subset generation
        //hence %2 will give present row, and +1 the row before
        
        //filling up the array
        //we're using a complete 1 based scale to denote nullity using 0
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(!j)//zero sum
                //if the sum is zero then the collection is seperatable in 2 equal sum subsets
                    dp[i%2][j]=true;
                //case when j != - & i == 0
                else if(!i)
                    dp[i%2][j]=false;
                else if(a[i-1]<=j)
                    //present arr element qualifies for inclusion
                    dp[i%2][j] = 
                        //inclusion of current element for the subset of sum =j
                        dp[(i+1)%2][j-a[i-1]]
                            ||
                        //checking if it is already present
                        dp[(i+1)%2][j];
                else dp[i%2][j] = dp[(i+1)%2][j];
                
                
            }
        
        //if subset for sum/2 exists thus the remaining elements would
        //constitute for the remaining sum/2
        return dp[n%2][sum/2];
        
    }
};

class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        int sum  = 0;
        for(int i=0;i<n;i++)sum+=a[i];
        if(sum%2)return false;
        
        bool subset[2][sum+1];
        //since we've to return for sum/2
        //therefore we construct an array that'll let us know
        //if there is a subset of sum/2, thus the remaining will
        //be s/2 hence covered.
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(!j)
                    subset[i%2][j]=true;
                else if(!i)//if there exists zero element, no sum is possible. 
                           //hence we use 1 scaled indexing
                    subset[i%2][j]=false;
                else if(a[i-1]<=j)
                    subset[i%2][j] =
                        //considering arr[i] in the subset
                        subset[(i+1)%2][j-a[i-1]] || 
                        //excluding it
                        subset[(i+1)%2][j];
                        //no chance of inclusion if the val is greater than the sum
                else subset[i%2][j] = subset[(i+1)%2][j];
            }
        return subset[n%2][sum/2];
    }
};

class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n) 
    {
        int sum = 0;
        int i, j;
    
        //storing sum of all elements.
        for (i = 0; i < n; i++) 
        sum += a[i];
    
        //if the total sum is odd, returning false. 
        if (sum % 2 != 0) 
        return false;
    
        //the value of subset[i%2][j] will be true if there exists 
        //a subset of sum j in arr[0, 1, ...., i-1].
        bool subset[2][sum + 1];
    
        for (i = 0; i <= n; i++) 
        {
            for (j = 0; j <= sum; j++) 
            {
                //a subset with sum 0 is always possible.
                if (j == 0) 
                subset[i % 2][j] = true;
    
                //if there exists zero element, no sum is possible.
                else if (i == 0)
                    subset[i % 2][j] = false;
                    
                //else we update the value of subset[i%2][j].
                else if (a[i - 1] <= j)
                    subset[i % 2][j] =
                        subset[(i + 1) % 2][j - a[i - 1]] || subset[(i + 1) % 2][j];
                else
                    subset[i % 2][j] = subset[(i + 1) % 2][j];
            }
        }
        //returning the result.
        return subset[n % 2][sum / 2];
    }
};

class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        int sum  = 0;
        for(int i=0;i<n;i++)sum+=a[i];
        if(sum%2)return false;
        
        bool subset[2][sum+1];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(!j)
                    subset[i%2][j]=true;
                else if(!i)//if there exists zero element, no sum is possible. 
                           //hence we use 1 scaled indexing
                    subset[i%2][j]=false;
                else if(a[i-1]<=j)
                    subset[i%2][j] =
                        subset[(i+1)%2][j-a[i-1]] || subset[(i+1)%2][j];
                else subset[i%2][j] = subset[(i+1)%2][j];
            }
        return subset[n%2][sum/2];
    }
};


class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)sum+=a[i];
        
        if(sum%2!=0)return false;
        
        bool subset[2][sum+1];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
                if(i==0)subset[i%2][j]=false;
                else if(j==0)subset[i%2][j]=true;
                else if(a[i-1]<=j)
                    
    }
};

class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        int sum  = 0;
        for(int i=0;i<n;i++)sum+=a[i];
        if(sum%2)return false;
        
        bool subset[2][sum+1];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(!j)
                    subset[i%2][j]=true;
                else if(!i)//if there exists zero element, no sum is possible. 
                           //hence we use 1 scaled indexing
                    subset[i%2][j]=false;
                else if(a[i-1]<=j)
                    subset[i%2][j] =
                        //considering arr[i] in the subset
                        subset[(i+1)%2][j-a[i-1]] || 
                        //excluding it
                        subset[(i+1)%2][j];
                        //no chance of inclusion if the val is greater than the sum
                else subset[i%2][j] = subset[(i+1)%2][j];
            }
        return subset[n%2][sum/2];
    }
};