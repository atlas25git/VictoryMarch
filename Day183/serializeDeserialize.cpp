/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    private:
    stringstream ss;
    
    void su(TreeNode* root)
    {
        if(!root)ss<<"# ";
        else{
            ss<<root->val<<" ";
            su(root->left);
            su(root->right);
        }
    }
    
    TreeNode* du()
    {
        string data;
        ss>>data;
        if(data == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(data));
        root->left = du();
        root->right = du();
        return root;
    }
    public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ss.clear();
        su(root);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        ss.clear();
        ss<<data;
        return du();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));