class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        if(!root) return NULL;

        root->left = removeLeafNodes(root -> left, target);
        root->right = removeLeafNodes(root -> right, target);

        if(root -> val == target && !root -> left && !root -> right) {
            return NULL;
        }
        
        return root;
    }
};