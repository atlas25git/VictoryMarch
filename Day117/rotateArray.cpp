class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    
    void rotUtil(int l,int r,int arr[],int n){
        while(l<r){
            swap(arr[l],arr[r]);
            l++,r--;
        }
    }
    
    void rotateArr(int arr[], int d, int n){
        
        rotUtil(0,d-1,arr,n);
        rotUtil(d,n-1,arr,n);
        rotUtil(0,n-1,arr,n);
    }
};