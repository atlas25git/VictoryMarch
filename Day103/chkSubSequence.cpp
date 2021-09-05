class Solution
{
    public:
    //Function to check if a string is subsequence of other string.
    bool isSubSequence(string A, string B)
    {
        int i=0,j=0;
        while(i<B.size() && j<A.size())
        {
            if(B[i]==A[j])j++;
            i++;
        }
        return (j==A.size());
    }
};