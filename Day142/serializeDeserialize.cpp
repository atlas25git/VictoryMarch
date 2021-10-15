class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream out;
        serialize(root,out);
        // cout<<out.str()<<endl;
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream in(data);
        return deserialize(in);
    }
    
 private:
    
    void serialize(TreeNode* root, stringstream& out)
    {
        if(root){
            out<<root->val<<' ';
            serialize(root->left,out);
            serialize(root->right,out);
        }else{
            out<<"# ";
        }
    }
    
    TreeNode* deserialize(stringstream& in)
    {
        string val;
        in>>val;
        if(val=="#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
