class Solution {
public:
        static int distributeCoins(TreeNode* root, TreeNode* parent= NULL) {
        if (!root) return 0;
        int  moves=distributeCoins(root->left, root)+distributeCoins(root->right, root);
        int x=root->val-1;
        if (parent) parent->val += x;
        moves+=abs(x);
        return moves;
    }
};