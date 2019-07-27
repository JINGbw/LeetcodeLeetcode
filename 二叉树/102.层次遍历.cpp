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
    vector<vector<int>> levelOrder(TreeNode* root) {
     //二叉树的后序遍历使用栈
    //二叉树的层次遍历 ，因为是先入先出的，是广度优先遍历BFS，使用队列
    //二叉树的深度遍历， 因为是先入后出的 ， DFS使用栈 
    //空间时间复杂度O(N)
    
        //遇到的问题：queue <TreeNode * > 结构体 在for循环中直接使用qq.size() 计算出来是错误的 存为int 就正确了
        vector<vector<int>> res;    
        if (!root)
            return res;
        queue <TreeNode * > qq; 
        TreeNode *p;//临时节点 
        qq.push(root);
        
        while (!qq.empty()){ 
            vector<int> tmp;
            int width=qq.size();
            //走到这里，qq中存放了上一层所有的节点
            for (int i= 0 ; i< width ;i++){
            p = qq.front();
            tmp.push_back(p->val);
            qq.pop();
            if (p->left)//这里增加的左右叶子节点会是下一层的 
                qq.push(p->left);
            if (p->right)
                qq.push(p->right);
            }
           res.push_back(tmp);
        }
       return res;
    }
};
