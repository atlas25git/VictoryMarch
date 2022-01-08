class Solution {
public:
    int maxProfit(vector<int>& a) {
        // int i=0,j=a.size()-1;
        int ans = INT_MIN;
        int minE = a[0];
        for(int i=1;i<a.size();i++)
        {   
            if(a[i]>minE)
                ans = max(ans,a[i]-minE);
            minE = min(minE,a[i]);
        }
        
        return ans==INT_MIN?0:ans;
    }
};