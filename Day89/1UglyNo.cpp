//Basic approach increment count till smaller than n,
//for valid no return 1, else 0, hence added in the count
// C++ program to find nth ugly number
#include <iostream>
using namespace std;

// This function divides a by greatest
// divisible power of b
int maxDivide(int a, int b)
{
	while (a % b == 0)
		a = a / b;
		
	return a;
}

// Function to check if a number is ugly or not
int isUgly(int no)
{
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);

	return (no == 1) ? 1 : 0;
}

// Function to get the nth ugly number
int getNthUglyNo(int n)
{
	int i = 1;
	
	// Ugly number count
	int count = 1;

	// Check for all integers untill ugly
	// count becomes n
	while (n > count)
	{
		i++;
		if (isUgly(i))
			count++;
	}
	return i;
}

// Driver Code
int main()
{
	
	// Function call
	unsigned no = getNthUglyNo(150);
	cout << "150th ugly no. is " << no;
	return 0;
}


// DP

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    
	    ull ugly[n];
	    ull i2=0,i3=0,i5=0;
	    ull m2=2,m3=3,m5=5;
	    ull nxt = 1;
	    
	    ugly[0]=1;
	    //here we optimally do what is better given by choosing first n elements
        //out of increasng powers of 2,3,5 and their multiplications with each other
        
	    for(int i=1;i<n;i++)
	    {   
	        //we keep multiplying the nos fro 1 to n
	        //first by 2, then 3 and 5, and do scuh in a 
	        //sorted order by maintaining orderly indices, thus each
	        //value in [1,n] is multiplied by all the prime set
	       //  (1) 1×2, 2×2, 3×2, 4×2, 5×2, … 
        //     (2) 1×3, 2×3, 3×3, 4×3, 5×3, … 
        //     (3) 1×5, 2×5, 3×5, 4×5, 5×5, …
	        nxt = min({m3,m2,m5});
	        ugly[i]=nxt;
	        
	        if(nxt == m2)
	        {
	            i2++;
	            m2 = ugly[i2]*2;
	        }
	        if(nxt == m3)
	        {
	            i3++;
	            m3 = ugly[i3]*3;
	        }
	        if(nxt == m5)
	        {
	            i5++;
	            m5 = ugly[i5]*5;
	        }
	    }
	    return nxt;
	    
	}
};