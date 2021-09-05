class Solution
{
    public:
    //Function to find minimum number of characters which Ishaan must insert  
    //such that string doesn't have three consecutive same characters.
    int modified(string a)
    {
    // int count=0;
    // for(int i=0;i<a.length()-2;)
    // {if(a[i]==a[i+1]&&a[i+1]==a[i+2])count++,i+=2;else i+=1;}
    // return count;}
    
    //4 count
    int ans=0,sum=1,lt=3;
    for(int i=1;a[i];i++){
        
        if(a[i]==a[i-1])sum++;
        else ans += (sum-1)/(lt-1),sum=1;
    }
    ans+=(sum-1)/(lt-1);//eqn will converge to zero if anything less than lt;
    return ans;
    }
    
    };