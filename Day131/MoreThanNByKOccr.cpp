class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        vector<pair<int,int>> res(k-1,{0,0});int k1 = k-1;
        int count = 0;
        //there can never be more than k-1 elements in output
        for(int i=0;i<n;i++)
        {
            int j=0;
            
            //for the current element if the element is present in the 
            //output array we increase it's frequency by the times it appeared.
            for(j=0;j<k1;j++)
            {
                if(res[j].first == arr[i])
                    {
                    res[j].second += 1;
                    break;
                    }
            }
            
            //since it didn't break and hence we conclude the number isn't present
            //Now we add the number in our op array
            if(j==k1)
            {   
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
            //again since it didn't break hence we conclude the op array doesn't have space.
            //hence reducing count of each element acc to Moore's algorithm
            if(l==k1)
            {
                //no place empty thus reducing the count adhereing to moore's
                //theorem
                for(l=0;l<k1;l++)res[l].second -= 1;
            }
            }
        }
        //for(auto x: res)cout<<"F:"<<x.first<<" "<<x.second<<endl;
        
        //brute force check up if the element in question is actually occurring more than
        //n/k times.
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