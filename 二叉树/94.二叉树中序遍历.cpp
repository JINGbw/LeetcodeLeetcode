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
    vector<int> inorderTraversal(TreeNode* root) {
//         //二叉树中序遍历
//         //左中右 递归
//         vector<int>  res;
//         mid(root,res);
//         return res;
//         }
//     void  mid(TreeNode* root,vector<int> & res){
//         if (root==nullptr)
//             return ;
//         if (root->left!=nullptr){
//             mid(root->left,res);
//         }
//         res.push_back(root->val);
//         if (root->right!=nullptr){
//             mid(root->right,res);
//         }
//         return ; 
//     }
        
        //非递归  左 根 右 
        // 每次循环都从栈中取出一个元素 一定是先取左边的，再取根节点，再取右节点 
        vector<int> res;
        stack<TreeNode *> ss;
        if (root==nullptr)
            return res;
        TreeNode *p = root;
       while (!ss.empty()||p){
          //走到左下角 
           while (p){
               ss.push(p);
               p = p->left;
           }
           
           p = ss.top();
           ss.pop();
           res.push_back(p->val);
           p = p->right;
       }
        return res;
    }
    
    
};
