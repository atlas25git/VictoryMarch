class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        long long s=0,e=v.size()-1;
        long long ans=INT_MIN;
        while(s<=e)
        {
            long long m = s+(e-s)/2;
            if(v[m]<=x)ans = max(ans,m);
            
            if(v[m]>x)e=m-1;
            else s = m+1;
        }
        return ans==INT_MIN?-1:ans;
        
    }
};
