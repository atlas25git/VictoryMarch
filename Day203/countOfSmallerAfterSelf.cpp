//Basically the idea here is that while performing  a classic mergesort we encounter 2 cases
//When merging 2 sorted arrays, if the curr in left array is greater then it makes a valid case
//Hence while merging the smaller elements of right array we maintai a cumulative count,
//which adds up in each element of left array, which is remaining, as ensuing elements will be greater,
//adhereing to the sorting order.

class Solution {
    vector<int> res;
    vector<pair<int,int>> aug;
    int n;
    
    public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        res.resize(n,0);
        for(int i=0;i<n;i++)
            aug.push_back({nums[i],i});
        mergeSort(0,n-1);
        return res;
    }
    
    void mergeSort(int start,int end)
    {
        if(start>=end)return;
        int m = start + (end-start)/2;
        mergeSort(start,m);
        mergeSort(m+1,end);
        mergeC(start,m,end);
    }
    
    void mergeC(int start,int m,int end)
    {
        vector<pair<int,int>> lt,rt;
        fill(lt,start,m);
        fill(rt,m+1,end);
        
        int i=0,j=0,rtos = 0,k=start;
        
        while(i<lt.size() && j<rt.size())
        {
            if(lt[i] < rt[j])
                aug[k++] = lt[i],
                res[lt[i++].second] += rtos;
            
            else if(lt[i] > rt[j])
                aug[k++] = rt[j++],
                rtos++;
        }
        
        while(i<lt.size())
            aug[k++] = lt[i],
            res[lt[i++].second] += rtos;
        
        while(j<rt.size())
            aug[k++] = rt[j++];
        
        return;
    }
    
    void fill(vector<pair<int,int>>& prop,int start,int end)
    {
        for(int i=start;i<=end;i++)
            prop.push_back(aug[i]);
    }
};