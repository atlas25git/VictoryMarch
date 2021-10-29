#include<bits/stdc++.h>

using namespace std;

char SearchHighestFreqChar(char* str)
{
    
    int count[256] = {0};
 
    int len = strlen(str);
    int max = 0;  // Initialize max count
    char result;   // Initialize result
 
    for (int i = 0; i < len; i++) {
        count[str[i]]++;
        if (max < count[str[i]]) {
            max = count[str[i]];
            result = str[i];
        }
    }
 
    return result;
}

int GetCharOccurrence(string a, char c)
{	
	int count=0;
	for(auto x : a)
	{
		if(x==c)
		     count++;
	}
return count;
}

int main()
{
    string inputString;
    cin>>inputString;
    char maxChar = SearchHighestFreqChar((char*)inputString.c_str());
    cout<<GetCharOccurrence(inputString,maxChar)<<endl;
    return 0;
}