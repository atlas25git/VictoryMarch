class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        vector<pair<int,int>> res(k-1,{0,0});int k1 = k-1;
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            int j=0;
            
            for(j=0;j<k1;j++)
            {
                if(res[j].first == arr[i])
                    {
                    res[j].second += 1;
                    break;
                    }
            }
            
            if(j==k1)
            {   //cout<<"Called"<<endl;
                int l=0;
                for(l=0;l<k1;l++)
                {
                    if(res[l].second == 0)
                    {
                        res[l].first = arr[i];
                        res[l].second += 1;
                        break;
                    }
                }
                
            if(l==k1)
            {
                //no place empty thus reducing the count adhereing to moore's
                //theorem
                for(l=0;l<k1;l++)res[l].second -= 1;
            }
            }
        }
        //for(auto x: res)cout<<"F:"<<x.first<<" "<<x.second<<endl;
        
        for(int i=0;i<k1;i++)
        {
            int ac = 0;
            
            for(int j=0;j<n;j++)
                if(arr[j] == res[i].first)ac++;
            
            if(ac>n/k)count++;
        }
    return count;
    }
};


struct eleCount 
{
    int e; // Element
    int c; // Count
};
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) 
    {
        int count = 0;
        if (k < 2) //if k==1 n/k = n total count of elements.
        return 0;
    
        //because the elements that can appear more than n/k times
        //can atmost be k as, n/k * k =n;
        eleCount temp[k];
        for (int i = 0; i < k - 1; i++) 
            temp[i].c = 0;
    
        //iterating over the array.
        for (int i = 0; i < n; i++)
        {
            int j;
            //if arr[i] is already present in the element-count array temp[], 
            //then we increment its count.
            
            for (j = 0; j < (k - 1); j++) 
            {
                if (temp[j].e == arr[i]) {
                    temp[j].c += 1;
                    break;
                }
            }
            //if arr[i] is not present in temp[]
            if (j == k - 1)
            {
                int l;
                //if there is position available in temp[] then we place arr[i] 
                //in the first available position and set its count as 1.
                for (l = 0; l < k - 1; l++) 
                {
                    if (temp[l].c == 0) {
                        temp[l].e = arr[i];
                        temp[l].c = 1;
                        break;
                    }
                }
                //if all the position in the temp[] are filled then we
                //decrease count of every element by 1.
                //Moore's voting algorithm is used here.
                //we decrement the count of vote for every not of the same kind vote found.
                if (l == k - 1)
                    for (l = 0; l < k; l++) 
                        temp[l].c -= 1;
            }
        }
    
        //chceck step of moore's voting algorithm
        for (int i = 0; i < k - 1; i++) 
        {
            int ac = 0; 
            //calculating actual count of elements.
            for (int j = 0; j < n; j++)
                if (arr[j] == temp[i].e) 
                    ac++;
    
            //if actual count is more than n/k then we increment the answer.
            if (ac > n / k) 
                count++;
        }
        return count;
    }

};