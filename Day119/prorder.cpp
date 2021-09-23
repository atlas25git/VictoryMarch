vector <int> preorder(Node* root)
{
  stack<Node*> st({root});
  vector<int> ans;
  
  while(!st.empty())
  {
      Node* curr = st.top();
      st.pop();
      ans.push_back(curr->data);
      if(curr->right)st.push(curr->right);
      if(curr->left)st.push(curr->left);
  }
  return ans;
}