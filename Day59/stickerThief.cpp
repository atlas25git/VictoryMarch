class Solution 
{
    max(x,y){
        return x>y?x:y;
    }
    
    //Function to find the maximum money the thief can get.
    FindMaxSum(arr, n)
    { 
        //storing sum up to current element including and 
        //excluding it in respective variables.
        let incl_curr = BigInt(arr[0]);    
        let excl_curr = BigInt(0);  
        
        //storing sum up to previous element including and 
        //excluding it in respective variables.
        let incl_prev = incl_curr;
        let excl_prev = excl_curr;
        
	    for(let i = 1; i <n; i++)
	    {
	        //updating sum up to current element excluding it as maximum
            //of sum up to previous element excluding and including it.
	        excl_curr = this.max(incl_prev, excl_prev);
	        
	        //updating sum up to current element including it as sum up to 
            //previous element excluding it + current element.
            incl_curr = excl_prev + BigInt(arr[i]);
            
            //updating sum up to previous element including and 
            //excluding it for next iteration.
            excl_prev = excl_curr;  
            incl_prev = incl_curr;  
	    }
	    //returning the maximum of sum up to current element  
        //including and excluding it.
	    return this.max(excl_curr, incl_curr);
    }
}

class Solution
{   
    max(x,y){return x>y?x:y;}
    
    //Function to find the maximum money the thief can get.
    FindMaxSum(arr, n)
    { 
        let ic = BigInt(arr[0]);
        let ec = BigInt(0);
        
        let ep = ec;
        let ip = ic;
        
        for(let i=1;i<n;i++)
            {
                ic = BigInt(arr[i]) + ep;
                ec = this.max(ip,ep);
                
                ip = ic;
                ep = ec;
            }
            return this.max(ic,ec);
    }
}
