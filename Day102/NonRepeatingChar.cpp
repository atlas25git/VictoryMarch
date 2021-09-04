class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       vector<int> h(26,0);
       for(auto x: S)h[x-'a']++;
       bool flag=false;
       for(int i=0;i<S.size();i++)
       {
           if(h[S[i]-'a'] == 1){
               flag = true;
               return S[i];
           }
       }
       return '$';
    }
};