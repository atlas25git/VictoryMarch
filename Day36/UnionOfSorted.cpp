class Solution{
    public:
    
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i = 0, j = 0; 
        vector<int> ans;
        //Using two pointers i and j over the two arrays which helps
        //in storing the smaller element.
        while (i < n && j < m) 
        { 
            //Updating the pointer i until we have identical 
            //elements at consecutive position in arr1.
            while(  i+1<n  &&  arr1[i]==arr1[i+1]  )
                i++;
               
            //Updating the pointer j until we have identical 
            //elements at consecutive position in arr2.
            while(  j+1<m  &&  arr2[j]==arr2[j+1]  )
                j++;
                
        
            //Comparing element of the arrays arr1 and arr2 at pointers
            //i and j and accordingly storing the smaller element
            //and updating the pointers.
            if (arr1[i] < arr2[j]) 
                ans.push_back(arr1[i++]);
          
            else if (arr2[j] < arr1[i]) 
                ans.push_back(arr2[j++]);
                
            else
            {
                //If arr1[i] is same as arr2[j], we update both pointers.
                ans.push_back(arr2[j++]);
                i++;
            }
        } 
        
        //Storing the remaining elements of first array (if there are any).
        while(i < n)
        {
            //Updating the pointer i until we have identical 
            //elements at consecutive position in arr1.
            while(  i+1<n  &&  arr1[i]==arr1[i+1]  )
                i++;
            
            //Storing the elements.
            ans.push_back(arr1[i++]);
        }
        //Storing the remaining elements of second array (if there are any).
        while(j < m)
        {
            //Updating the pointer j until we have identical 
            //elements at consecutive position in arr2.
            while(  j+1<m  &&  arr2[j]==arr2[j+1]  )
                j++;
            
             //Storing the elements
            ans.push_back(arr2[j++]);
        }
        
        //returning the list containing the union of the two arrays. 
        return ans;

    //alternate sol
    // set<int> s;
        // for(int i=0;i<n;i++)s.insert(arr1[i]);
        // for(int i=0;i<m;i++)s.insert(arr2[i]);
        // vector<int>res;
        // for(auto x:s)res.push_back(x);
        // return res;
        

    }
};