class Solution{
    public:
       //Function to sort the array into a wave-like array.
        void convertToWave(vector<int>& arr, int n){
        //Iterating over the array.
        for(int i=0;i<n-1;i=i+2)
                //Swapping two neighbouring elements at a time. 
                swap(arr[i],arr[i+1]); 
                
        
    }
};