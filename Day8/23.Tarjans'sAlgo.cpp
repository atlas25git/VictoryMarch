// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



bool compare1(vector<int> v1, vector<int> v2)
{
    return v1.front()<v2.front();
}

class Solution
{
    public:
    //vector to store the members of the strongly connected components.
    vector<vector<int>> ans;  
    vector<int> temp;   
    
    void findUtil(vector<int> adj[], stack<int> &st, int index[], int lowlink[], 
                                                        bool onstack[], int i) 
    {
        static int curr = 0;
    
        index[i] = lowlink[i] = ++curr;
    
        //pushing the ith node into the stack.
        st.push(i);
        
        //marking ith node '1' i.e. it is present in the stack.
        onstack[i] = 1; 
    
        for (int j = 0; j < adj[i].size(); ++j) 
        {
            //if adj[i][j] isn't visited, we call the function recursively.
            if (index[adj[i][j]] == -1)
            { 
                
                findUtil(adj, st, index, lowlink, onstack, adj[i][j]);
                //updating lowlink at ith index.
                lowlink[i] = min(lowlink[i], lowlink[adj[i][j]]);
            } 
            //else if the adj[i][j] node is visited and present in the stack.
            else if (onstack[adj[i][j]]) 
            { 
                //updating lowlink at ith index.
                lowlink[i] = min(lowlink[i], index[adj[i][j]]);
            }
        }
        
        //if lowlink[i]==index[i], it represents a strongly connected components
        if (lowlink[i] == index[i]) 
        { 
            int w = 0;
            //while stack is not empty and top element is not i.
            while (!st.empty() && st.top() != i)
            {
                //we keep popping top element from stack and pushing it in list
                //and marking it absent in stack.
                w = (int)st.top();
                temp.push_back(w);
                onstack[w] = 0;
                st.pop();
            }
            
            //we again pop the top element, store it in the list
            //and mark it absent in the stack. 
            w = (int)st.top();
            temp.push_back(w);
            
            //pushing the list in final answer list.
            ans.push_back(temp);
            temp.clear();
            onstack[w] = 0;
            st.pop();
        }
    }
    
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        int lowlink[V + 1], index[V + 1];

        //boolean array onstack is true if ith node is present in the stack.
        bool onstack[V + 1]; 
        
        stack<int> st;
    
        for (int i=0; i<V; ++i) {
            lowlink[i] = -1;
            index[i] = -1;
            onstack[i] = false;
        }
    
        for (int i=0; i<V; ++i) 
        {
             //if index[i] is -1, ith node is not visited.
            if (index[i] == -1)
            {
                //we call the findUtil function.
                findUtil(adj, st, index, lowlink, onstack, i); 
            }
        }
        
        //sorting all the lists in final answer list.
        for(int i=0; i<ans.size(); i++){
            sort(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end(),compare1);
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends