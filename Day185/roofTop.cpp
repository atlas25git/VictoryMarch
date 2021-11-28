
class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int arr[], int N)
    {
       int c=0,m=0;
       for(int i=0;i<N-1;i++)
       {
           if(arr[i]<arr[i+1])c++;
           else{
               m = max(c,m);
               c = 0;
           }
       }
       
       return max(c,m);
    }
};
