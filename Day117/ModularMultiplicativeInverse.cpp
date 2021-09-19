class Solution{
    public:
    int modInverse(int a, int m)
    {
        // taking modulo of a with m
        a = a%m;
        
        // For every number x, check if (a*x)%m is 1
        for (int x=1; x<m; x++)
           if ((a*x) % m == 1)
              return x;
    	return -1;
    }
};