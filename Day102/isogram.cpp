class Solution
{
    public:
    //Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        unordered_set<char>c;
        for(auto x:s)c.insert(x);
        return c.size()==s.size();
    }
};
