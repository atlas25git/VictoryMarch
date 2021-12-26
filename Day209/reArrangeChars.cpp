class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string s)
    {
    	vector<int> mp(26,0);
        for(auto x: s)
            mp[x-'a']++;
        int bal = s.size()/2;
        if(s.size()&1)bal++;
        for(auto x: mp)
            if(x>(bal))
                return "";
        
        auto cmp = [](pair<char,int> a,pair<char,int> b){return a.second<b.second;};
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)> pq(cmp);
        
        for(int i=0;i<26;i++)
            if(mp[i])
            pq.push({(char)('a'+i),mp[i]});
        
        string ans;
        
        while(pq.size()>1)
        {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            
            x.second--;
            y.second--;
            
            ans += x.first;
            ans += y.first;
           // cout<<x.second<<" "<<y.second<<" "<<pq.size()<<" \n";
            if(x.second>0)pq.push(x);
            if(y.second>0)pq.push(y);
        }

        if(pq.empty())
                return ans;
        auto x = pq.top();
        // cout<<x.second<<" "<<x.first<<endl;
        if(x.second > 0)
            ans += x.first;
        return ans;
    }
};