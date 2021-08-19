#define m 1000000007
class Solution
{
    public:
    // Returns count of ways n people 
    // can remain single or paired up. 
    int countFriendsPairings(int n) 
    { 
        long long a = 1, b = 2, c = 0; 
    	if (n <= 2) { 
    		return n; 
    	} 
    	for (int i = 3; i <= n; i++)
    	{ 
    		// using modular arithmentic properties.
    		c = ( b%m //goes alone thus no group addn
                    +
//                     f(n) = ways n people can remain single 
//        or pair up.

// For n-th person there are two choices:
// 1) n-th person remains single, we recur 
//    for f(n - 1)
// 2) n-th person pairs up with any of the 
//    remaining n - 1 persons. We get (n - 1) * f(n - 2)

// Therefore we can recursively write f(n) as:
// f(n) = f(n - 1) + (n - 1) * f(n - 2) would make for an ordered
                    //set thus incrementing the count
                    //i people, i forms a pair including one from the lot
                    //there total ways = i-1
                    //remaining i-2 // ways these could form group is given 
                    //by f(n-2);
                     ( ( (i - 1)%m  *  a%m )%m ) %m )%m ; 
    		a = b; 
    		b = c; 
    	} 
    	return c; 
    }
};  


class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int mod = 1e9+7;
        long long int a=1,b=2,c=0;
        if(n<=2)return n;
        for(int i=3;i<=n;i++)
        {
            c = (b%mod + ( ( a%mod * (i-1)%mod ) %mod ) %mod )%mod;
            a=b;
            b=c;
        }
        return c;
    }
};    
 