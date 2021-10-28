vector <int> preorder(Node* root)
{
  stack<Node*> st;
  st.push(root);
  vector<int> ans;
  while(!st.empty())
  {
      auto cr = st.top();
      st.pop();
      ans.push_back(cr->data);
      if(cr->right)st.push(cr->right);
      if(cr->left)st.push(cr->left);
  }
  return ans;
  
}