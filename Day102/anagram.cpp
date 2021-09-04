class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        // cout<<int('A')<<endl;
        int an=a.size(),bn=b.size();
        if(an!=bn)return false;
        int ch[26]={0};
        for(char x: a)ch[int(x-97)]++;
        for(char x:b)ch[int(x-97)]--;
        for(int x:ch)if(x>0)return false;
        return true;
        
        
    }

};