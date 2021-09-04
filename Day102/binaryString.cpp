class Solution
{
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a){
        
        int cnt=0;
        for(char c: a)if(c-'0')cnt++;
        return cnt*(cnt-1)/2;
        
    }

};