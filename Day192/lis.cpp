class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        //our goal is to store at i, min no with which an inc. subsequence
        //of len i could end, and thus for subsequen arr elements the len 
        //will be increasing as greater elements are discovered.
        vector<int>tail(n+1);
        tail[1]=a[0];
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>tail[len])tail[++len]=a[i];//len inc
            else
            {   //rightful posn of our current arr element
                int ind = lower_bound(tail.begin()+1,tail.begin()+len,a[i])-(tail.begin());
                tail[ind] = a[i];
            }
        }
        return len;
    }
    
    int longestSubsequenceR(int n, int a[])
    {
        vector<int> lis(n,0);
        int len=0;
        lis[0]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]>lis[len])lis[++len]=a[i];
            else
            {
                lis[lower_bound(lis.begin(),lis.begin()+len,a[i])-lis.begin()] = a[i];
            }
        }
        return len+1;
    }
};