class Solution {
  public:
    int getCount(int n) {
        
        int ans = 0;
        
        //since for any number say n
        //we can write it as a sequence of numbers consecutively increasing by 1
        //starting at x as:
        //n = x,x+1,x+2.....,x+k; // k terms
        //n = k*x + (1,2,3....,k);
        //n = k*x + k(k+1)/2;
        //n - k(k+1)/2 = k*x
        //hence the starting number x should be a multiple of k
        //worst case analysis let's say rhs gr8r than zero
        //hence this implies => (n - k(k-1)/2) >0;
        //=> 2*n > k(k-1)
        // k < sqrt(2*n)
        
        auto lt = sqrt(2*n);
        
        for(int k=2;k<lt;k++)
        {
            int kx = (n - k*(k+1)/2);
            if(kx%k==0)ans++;
        }
        return ans;
    }
};