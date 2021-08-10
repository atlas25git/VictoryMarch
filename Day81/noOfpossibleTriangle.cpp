class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int a[], int n)
    {
        //basically our approach here is to sort the array and compute
        //all the possible triplet in one traversal per element, given the condn
        // i+j>k, k lying beyond them, and thus the largest such k would be the upper
        //bound, thus the dist covered would be included in the count.
        
        // if a<b<c ...ck, st a+b>ck, true for other condn. as well 
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n-2;i++)
        {   
            int k = i+2;
            for(int j=i+1;j<n;j++)
            {
                while(k<n && a[i] + a[j] > a[k])k++;
                ans += k-j-1;// -1 for` the j included between the range ofg i+1 and k
            }
        } 
        return ans;
    }
};