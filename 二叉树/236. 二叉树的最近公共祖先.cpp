/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//递归解法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==p ||root==q )
            return root;
        TreeNode *left;
        TreeNode *right;
        left = lowestCommonAncestor( root->left ,  p, q);
        right = lowestCommonAncestor( root->right ,  p, q);
        if(left&&!right)
            return left;
        if(!left&&right)
            return right;
        if(!left&&!right)
            return nullptr;
        return root;
    }
};
