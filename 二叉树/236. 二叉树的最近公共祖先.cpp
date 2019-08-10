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
        //在左边找到了
        if(left&&!right)
            return left;
        //在右边找到了
        if(!left&&right)
            return right;
        //两边都没找到 
        if(!left&&!right)
            return nullptr;
        //在左边找到一个，在右边找到一个就是root 
        return root;
    }
};
