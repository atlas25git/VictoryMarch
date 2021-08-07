int getSpecialSubstring(string s, int k, string charValue)
{
    if(!k)return 0;
    int c = 0;
    int l=0,r=0;
    int ans = 0;
    while(r<s.length())
    {
        while(r<s.length() && c<=k)
        {
            int p = s[r]-'a';
            if(charValue[p] == '0')
            {
                if(c+1>k)break;
                else c++;
            }
            r++;
            if(c<=k)ans = max(ans,r-l);
        }
      
        
        while(l<r)
        {
            int p = s[l]-'a';
            l++;
            if(charValue[p] == '0')c--;
            if(c<k)break;
        }
    }
    return ans;
}