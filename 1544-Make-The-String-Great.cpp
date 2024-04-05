/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int goodNodes(TreeNode* root, int maxx=INT_MIN){
        if(!root) return 0;
        int me = root->val >= maxx;
        int l =  goodNodes(root->left, max(maxx, root->val));
        int r =  goodNodes(root->right, max(maxx, root->val));
        return me + l + r;
    }
};