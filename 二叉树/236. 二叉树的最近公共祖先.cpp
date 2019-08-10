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
//递归解法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==p ||root==q )
            return root;
        TreeNode *left;
        TreeNode *right;
        left = lowestCommonAncestor( root->left ,  p, q);
        right = lowestCommonAncestor( root->right ,  p, q);
        //在左边找到了
        if(left&&!right)
            return left;
        //在右边找到了
        if(!left&&right)
            return right;
        //两边都没找到 
        if(!left&&!right)
            return nullptr;
        //在左边找到一个，在右边找到一个就是root 
        return root;
    }
};

//非递归解法
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //非递归解法就是后序非递归遍历 
        if(root==nullptr)
            return root;
        stack<TreeNode* >s;
        vector<TreeNode* > vec;// p和q的公共祖先
        bool tag1 = false; // true:找到p
        bool tag2 = false; // true:找到q
        s.push(root);
        TreeNode* lastRoot = root;
        while (!s.empty()) // lastRoot(区分从左/右孩子返回)
    {
        root = s.top();
        if (root == p) {
            if(tag1 == false && tag2 == false)
                vec.push_back(root);
            tag1 = true;
        }
        else if (root == q) {
            if (tag2 == false && tag1 == false)
                vec.push_back(root);
            tag2 = true;
        }
        if (!tag1 && !tag2)
            vec.push_back(root); // 公共祖先入vector
        // 找到p,q并且root在公共祖先数组中
        if (tag1 && tag2 && find(vec.begin(), vec.end(), root) != vec.end())
            return root;
        // root的孩子节点还没访问
        if (lastRoot != root->right)
        {
            if (lastRoot != root->left) {
                if (root->left != nullptr) {
                    s.push(root->left);
                    continue;
                }
            }
            if (root->right != nullptr) {
                s.push(root->right);
                continue;
            }
        }
        // 孩子节点访问完，弹栈向上回溯
        lastRoot = root;
        s.pop();
    }
    return nullptr;
        
    }
