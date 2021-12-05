class Solution {
public:
    int numTrees(int n) {
        
        long long f = 1,s;
        for(int i=1;i<=n;i++)
            s = (2*(2*i-1)*f/(i+1)),
            f=s;

        return s;
    }
    
};