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
    int kthSmallest(TreeNode* root, int k) {
        //题目：二叉搜索树中第K小的元素，二叉搜索树中序遍历是升序的
        //思路：中序遍历（递归），过程中减小k,当k=1的时候返回该节点
        //时间：O(K) 空间：O(1)
        if (root==nullptr||k==0)
             return 0;
        TreeNode * p = mid(root,k);
        return p->val;
    }
    TreeNode* mid(TreeNode* root,int &k){
       //每一次迭代k减小1 ,一直到k为1的时候为第k大的树中的元素
        TreeNode *target = nullptr; 
        //在左子树吗 
        if (root->left)
            target = mid(root->left ,k);
        //如果左边没找到，看中间是不是
        if (!target){
            if(k==1)
                target = root; 
        } 
        k--;
        //在右子树吗 
        if (root->right&&!target)
            target = mid(root->right,k); 
        return target;
    }
};
