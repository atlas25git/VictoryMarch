class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        string res;
        string cw;
        vector<string> words;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '.')
                words.push_back(cw),cw="";
            else cw += s[i];
        }
        words.push_back(cw);
        for(int i=words.size()-1;i>=0;i--)
        {
            res += words[i];
            if(i)res+='.';
        }
        return res;
    } 
};