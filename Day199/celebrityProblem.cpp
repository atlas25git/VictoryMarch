// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        vector<int> indegree(n,0),outdegree(n,-1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == j)continue;
                indegree[j] += knows(i,j);
                outdegree[i] += knows(i,j);
            }
        }
        // for(auto x: indegree)cout<<x<<" ";
        // cout<<"\n";
        // for(auto x: outdegree)cout<<x<<" ";

        for(int i=0;i<n;i++)
        {
            if(outdegree[i] == -1 && indegree[i] == n-1)
                return i;
        }
        return -1;
    }


    //O(n) Solution
    int findCelebrity1(int n) {
        int candidate = 0;

        for(int j=1;j<n;j++)
            if(knows(candidate,j))
                candidate = j;
        
        for(int k = 0;k<n;k++)
            {
            if(candidate == k)continue;
            if(knows(candidate,k) || !knows(k,candidate))
                return -1;
            }
        return candidate;
    }
};