class Solution {
public:
    int maxArea(vector<int>& ht) {
        int i=0,j=ht.size()-1;
        int ans=INT_MIN;
        while(i<j)
        {
            if(ht[i]==ht[j])
                ans=max(ans,(j-i)*min(ht[i++],ht[j--]));
            else if(ht[i]<ht[j])
                ans=max(ans,abs(j-i)*min(ht[i++],ht[j]));
            else    
                ans=max(ans,abs(j-i)*min(ht[i],ht[j--]));

        }
        return ans;
    }
};