class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        
        //the floyd warshal algo is proved on the grounds that
        //any distance n is reachable in n steps, keeping the step size=1
        //thus the relative speed of both the pointers that's 1
        //now whenever they enter the cycle they'll be some k dist apart
        //k>0 and thus they'll converge at some point.
        
        pair<int,int> tortoise = {arr[0],0};
        pair<int,int> hare = {arr[0],0};
        
        while(1)
        {
            tortoise.second = tortoise.first;//curr index
            tortoise.first = arr[tortoise.first];//val at curr index, next pointer
            
            
            hare.second = hare.first;
            hare.first = arr[arr[hare.first]];
            
            if(tortoise.first == hare.first)break;
        }
        
        tortoise = {arr[0],0};
        
        while(tortoise.first != hare.first)
        {
            tortoise.second = tortoise.first;
            tortoise.first = arr[tortoise.first];
            
            hare.second = hare.first;
            hare.first = arr[hare.first];
        }
    
            
        return vector<int>{tortoise.second,hare.second};
    }
};