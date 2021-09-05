class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(s.size()<p.size())return "-1";
        vector<int> shash(26),phash(26);
        for(auto x: p)phash[x-'a']++;
        
        int si=-1,begin=0,cnt=0,len=0,mL=INT_MAX;
        
        for(int i=0;s[i];i++)
        {
            char x = s[i];
            shash[x-'a']++;
            
            if(phash[x-'a'] && shash[x-'a']<=phash[x-'a'])
                cnt++;
            if(cnt == p.size())
            {
                while(!phash[s[begin] - 'a'] || shash[s[begin]-'a'] > phash[s[begin]-'a'])
                {
                    if(phash[s[begin]-'a']<shash[s[begin]-'a'])
                        shash[s[begin]-'a']--;
                    begin++;
                }
                len = i-begin+1;
                if(len<mL)
                {
                    mL = len;
                    si = begin;
                }
            }
        }
        
        if(si==-1)return "-1";
        else return s.substr(si,mL);
        
    }
};

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(s.size()<p.size())return "-1";
        
        vector<int> shash(26);
        vector<int> phash(26);
        for(auto x: p)phash[x-'a']++;
        int cnt=0;
        int begin=0;
        int si = -1;
        int len = 0;
        int minLen = INT_MAX;
        
        for(int i=0;s[i];i++)
        {   
            char x = s[i];
            shash[x-'a']++;
            
            if(phash[x - 'a'] != 0 && shash[x-'a']<=phash[x-'a'])
                //incrementing even after equality bcoz
                //it isn't yet at the stage where all elements have been
                //discovered 
                cnt++;
            
            if(cnt == p.size())
            {
                while(shash[s[begin]-'a']>phash[s[begin]-'a'] || phash[s[begin] - 'a']==0)
                {
                    if(shash[s[begin]-'a']>phash[s[begin]-'a'])
                        shash[s[begin]-'a']--;
                    begin++;
                }
                len = i-begin+1;
                if(len<minLen)
                {
                    si = begin;
                    minLen = len;
                }
            }
        }
        if(si==-1)return "-1";
        else return s.substr(si,minLen);
    }
};