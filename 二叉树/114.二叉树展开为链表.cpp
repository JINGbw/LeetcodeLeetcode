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
    void flatten(TreeNode* root) {
        //题目：二叉树原地展开为链表
        //展开左子树，展开右子树，再把当前子树展开（根节点的访问在左右节点之后，所以是后序遍历）
     //（可以理解为后序遍历  虽然左右子树展开的顺序可以调换，也不是前序）
     //注意：后序遍历是 左右根
        // 递归：终止条件：叶子节点相当于左右为空，不用展开了。
        // 1.先把左边展开 2. 把右边展开 3. 把右边展开的接到左边展开的后面
        if (!root)return;//对于输入是否为空的判断
        if (!root->left&&!root->right){ 
            //如果是叶子节点，不展开返回//是循环停止条件
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *temp =root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root!=nullptr)
            root=root->right;
        root->right = temp;
    }
};
