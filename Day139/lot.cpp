class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      vector<int> res;    
      queue<Node*> q;
      q.push(node);
      while(!q.empty())
      {
          Node* t = q.front();
          q.pop();
          res.push_back(t->data);
          
          if(t->left)q.push(t->left);
          if(t->right)q.push(t->right);
          
      }
      return res;
    }
};