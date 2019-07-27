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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        //题目：求二叉树所有从根节点到叶子节点 总和等于给定目标值的所有路径
        //思路：二叉树的深度优先遍历（类似前序遍历）
        vector<int> cur;
        vector<vector<int> >  res;
        if (root==nullptr)
            return res; 
        find(root,sum,cur,res); 
        return res;
    }
    //二叉树中是否有满足目标和的路径，有的话就压入cur,压入res 
    //递归终止条件1.  当前节点为叶节点，如果和为路径和为目标和，存储,在数组中删除当前节点，返回 
    //           2.  当前节点为叶节点，和不为目标和，删除当前节点，返回 
     
    void find(TreeNode *root, int target, vector<int>& cur, vector<vector<int> > &res){
         cur.push_back(root->val);
        if (!root->left&&!root->right){
            if (root->val == target){
                 res.push_back(cur); 
                 cur.pop_back(); 
                 return;
            } 
            else {
                 cur.pop_back(); 
                 return;
            }
         } 
       
        if (root->left) find(root->left,target-root->val,cur,res); 
        if (root->right) find(root->right,target-root->val,cur,res);
        cur.pop_back();
    }
