class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        int min_i = 0, max_i = n;
        int i, j, median;
        
        //iterating over the arrays.
        while(min_i <= max_i)
        {
            i = (min_i+max_i)/2;
            j = (n+m+1)/2-i;
            
            //if i=n, it means that elements from arr[] in the second half is 
    		//an empty set. If j=0, it means that elements from brr[] in the  
    		//first half is an empty set.So, it is necessary to check that
    		//because we compare elements from these two groups. 
    		//Searching on right 
            if(i < n && j > 0 && brr[j-1] >= arr[i]){
                min_i = i+1;
            }
            //--and thus it is done
            //if i = 0, it means that elements from arr[] in the first half is 
    		//an empty set and if j = m, it means that elements from brr[] in 
    		//second half is an empty set. so it is necessary to check that
    		//because we compare elements from these two groups. 
    		//Searching on left 
            else if(i > 0 && j < m && brr[j] < arr[i-1]){
                max_i = i-1;
            }
            
            //we have found the desired halves. 
            else
            {
                //this condition happens when we don't have any elements in
    			//the first half from arr[] so we return the last element  
    			//in brr[] from the first half. 
                if(i == 0)
                    median = brr[j-1];  
                
                //and this condition happens when we don't have any elements 
    			//in the first half from brr[] so we return the last
    			//element in arr[] from the first half. 
                else if(j == 0)
                    median = arr[i-1];
                    
                else
                    median = max(arr[i-1], brr[j-1]);
                
                break;
            }
            
        }
        
        if((n+m)%2 == 1){
            return (double)median;
        }
        
        if(i == n){
            return (median+brr[j])/2.0;
        }
        
        if(j == m){
            return (median + min(arr[i], brr[j]))/2.0;
        }
        
        return (median + min(arr[i], brr[j]))/2.0;
        
    }
};