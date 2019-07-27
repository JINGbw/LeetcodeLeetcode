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
    vector<string> binaryTreePaths(TreeNode* root) {
    //题目：找到二叉树的所有路径
    //思路：递归（前序遍历）路径，是先经过根节点 ，再经过左右节点，一定是前序遍历
        vector<string> res;
        if (root==nullptr)
            return res;
        string s; 
        get(root,s,res);
        return res;
    }
     // 前序遍历递归：根 左 右
//       1.当前节点：1. 存入字符串中：  1. 是根节点 之间加
//                                    2. 非根节点 加箭头
//                  2. 是否满足递归终止条件（是叶子节点）：1.存入res
//                                                      2.s置位空
      
//       2. 递归左子树和右子树
    void get(TreeNode * root, string s, vector<string>&res){
        if (root==nullptr)
            return; 
          
        //如果是一个根节点，s中存一个数，否则存箭头加上这个数 
        s = s.empty() ? s+to_string(root->val) : s+"->"+ to_string(root->val);
        
        if (!root->left&&!root->right){
            res.push_back(s);
            s= "" ;
            return;  //一次循环的停止条件 当前节点是叶子节点，将结果存入res中 
        }
        get(root->left,s,res);
        get(root->right,s,res); 
        return;
    }
};
