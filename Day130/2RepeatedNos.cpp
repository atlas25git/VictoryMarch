class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        
        int flag = false;
        vector<int> res;
        for(int i=0;i<N+2;i++)
        {
            if(arr[abs(arr[i])]>0)
                arr[abs(arr[i])]*=-1;
            else //no has appeared previously
            {
                if(!flag){
                    flag = true;
                    res.push_back(abs(arr[i]));
                }else
                {
                    res.push_back(abs(arr[i]));
                }
            }
        }
        return res;
    }
};