class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
//     //二叉树的前序遍历（递归）
//         //总之就是先访问根节点，再访问左右节点
//         vector<int>res; 
//         precore(root,res);
//         return res;
//     }
//     void precore(TreeNode *root, vector<int> &res){
//     //一次递归终止条件。走到了叶节点 
//         if(root==nullptr) return;
//         res.push_back(root->val);
//         precore(root->left,res);
//         precore(root->right,res);
        
        
          //非递归写法 保存到res中的顺序 根节点-->左节点-->右节点
        //使用一个栈，每次取出一个 ，先压入右节点，再压入左节点
        if(root==nullptr)
            return {};
        vector<int> res;
        stack<TreeNode *>ss;  
        ss.push(root);
        while (!ss.empty()){
            TreeNode *tmp = ss.top();
            ss.pop();
            res.push_back(tmp->val);
            //因为是先左节点，再 右节点，由于栈取出来是反过来的，所以先存右节点再存左节点
            if (tmp->right)ss.push(tmp->right);
            if (tmp->left)ss.push(tmp->left);
        }
        
        return res; 
    }
};
