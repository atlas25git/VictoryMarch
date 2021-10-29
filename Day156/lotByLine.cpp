vector<vector<int>> levelOrder(Node* node)
{   
  vector<vector<int>> res;    
  queue<Node*> q;
  q.push(node);
  
  while(!q.empty())
  { 
      vector<int> tmp;
      int ls=q.size();
      
      while(ls)
      {
          Node* t = q.front();
          q.pop();
          tmp.push_back(t->data);
          if(t->left)q.push(t->left);
          if(t->right)q.push(t->right);
          ls--;
      }
      res.push_back(tmp);
  }
  
  return res;
  
  
}