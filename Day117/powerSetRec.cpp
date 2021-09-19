void powerSetUtil(string &str, vector<string>&v,int index = 0,string curr = "")
{
    int n = str.length();
    
    //base case
    if (index == n)
    {
       v.push_back(curr);    
       return;
    }   

    curr += str[index];
    powerSetUtil(str, v, index+1, curr);
    curr.erase(curr.size()-1);
    powerSetUtil(str, v, index+1, curr);
}

vector <string> powerSet(string s)
{
    vector<string> ans;
    powerSetUtil(s, ans);
    return ans;
}