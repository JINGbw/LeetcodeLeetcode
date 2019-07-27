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
    bool isValidBST(TreeNode* root) {
        //题目：验证是否是二叉搜索树 二叉搜索树的中序遍历是升序的
        //思路：先求中序遍历序列，再判断是否是升序的
        if (root==nullptr)
            return true;
        vector<int> res;
        mid(root , res);
        for(int i=0;i< res.size()-1;i++){
            if (res[i]>=res[i+1])
                return false;
        }
        return true;
    }
    void mid( TreeNode* root,vector<int> &res){
        if (root==nullptr)
            return ;
        mid(root->left,res);
        res.push_back(root->val);   
        mid(root->right,res);
        return ;
    }
};
