// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        string result = "";
        string curr_word = "";
        vector<string> words;
    
        //initially reversing individual words of the given string one by one.
        for (int i = 0; i < s.length(); ++i)
        {
            //if '.' is encountered, we store the word in list.
            if(s[i] == '.')
            {
                words.push_back(curr_word);
                curr_word = "";
            }
            //else adding the characters in current word in such
            //a way that original words get reversed.
            else
                curr_word += s[i];
        }
        //storing the last remaining word in list.
        words.push_back(curr_word);
        
        //now reversing the whole modified string by adding all 
        //the elements of list in a single string in reverse order.
        for (int i = words.size()-1; i>=0; --i)
        {
            result += words[i];
            if(i!=0)
                result += '.';
        }
        //returning the result.
        return result;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends