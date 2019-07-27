/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} //初始化结构体没有分号 
 * };//注意这里的分号 
 */ 
//注意：有同学面试考到手写二叉树的结构体 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    //题目：二叉树的后序遍历非递归方式
    //
        //栈 左右中
        //使用栈 和2个树节点指针 p,r 
        //p不为空说明 当前节点 是根节点或者 是没有存到res中的右节点 ,每次压入后都将p置空，再向栈中取
        //r记录上一个压入res的节点
        //压入res有两种情况，是右节点为空和上一个压入节点的值为右节点
        vector<int> res;
        stack<TreeNode *> ss;
        TreeNode *r = nullptr ;//记录上一个被压入res的节点
        TreeNode *p = root;//记录当前节点
        if (!root)return {};
       
        while (p||!ss.empty()){
            while(p!=nullptr){
                ss.push(p);
                p = p->left;
            }
            p = ss.top();
            if (!p->right ||p->right ==r ){
                //如果p右边为空 或者 上一个压入的是p的右节点，就该压入p了
                res.push_back(p->val);
                ss.pop();
                r = p;
                p = NULL;
            }
            else {
                p = p->right;
            }
            
        }
        return res;
    }
};
