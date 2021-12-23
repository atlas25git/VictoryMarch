class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      queue<Node*> q;
      vector<int> ans;
      q.push(node);
      while(!q.empty())
      {
          Node* t = q.front();
          q.pop();
          ans.push_back(t->data);
          if(t->left)q.push(t->left);
          if(t->right)q.push(t->right);
      }
      return ans;
    }
};