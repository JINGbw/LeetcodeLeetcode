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
    bool isSymmetric(TreeNode* root) {
        //题目：比较两个二叉树是否是镜像对称的：
        //思路：使用递归 
        //时间复杂度：O(n) ，因为我们遍历整个输入树一次，所以总的运行时间为 O(n) ，其中  n 是树中结点的总数。
         //空间复杂度：O(n)搜索队列需要额外的空间。在最糟糕情况下，我们不得不向队列中插入 O(n) 个结点。因 
        if (root==nullptr)
            return true;
        return subis(root,root);
    }
    bool subis(TreeNode *t1,TreeNode *t2){
        if (t1==nullptr&&t2==nullptr)
            return true; 
        //如果两个树有一个为空或者根节点的值不同，返回false
        if (t1==nullptr||t2==nullptr||t1->val!=t2->val)
            return false;
        return subis(t1->left,t2->right)&&subis(t1->right,t2->left);
    }
};
