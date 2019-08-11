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

// //非递归解法 - 二叉树的后序遍历 
//  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //非递归解法就是后序非递归遍历 
//         if(root==nullptr)
//             return root;
//         stack<TreeNode* >s;
//         vector<TreeNode* > vec;// p和q的公共祖先
//         bool tag1 = false; // true:找到p
//         bool tag2 = false; // true:找到q
//         s.push(root);
//         TreeNode* lastRoot = root;
//         while (!s.empty()) // lastRoot(区分从左/右孩子返回)
//     {
//         root = s.top();
//         if (root == p) {
//             if(tag1 == false && tag2 == false)
//                 vec.push_back(root);
//             tag1 = true;
//         }
//         else if (root == q) {
//             if (tag2 == false && tag1 == false)
//                 vec.push_back(root);
//             tag2 = true;
//         }
//         if (!tag1 && !tag2)
//             vec.push_back(root); // 公共祖先入vector
//         // 找到p,q并且root在公共祖先数组中
//         if (tag1 && tag2 && find(vec.begin(), vec.end(), root) != vec.end())
//             return root;
//         // root的孩子节点还没访问
//         if (lastRoot != root->right)
//         {
//             if (lastRoot != root->left) {
//                 if (root->left != nullptr) {
//                     s.push(root->left);
//                     continue;
//                 }
//             }
//             if (root->right != nullptr) {
//                 s.push(root->right);
//                 continue;
//             }
//         }
//         // 孩子节点访问完，弹栈向上回溯
//         lastRoot = root;
//         s.pop();
//     }
//     return nullptr;
        
//     }


//二叉树的后序遍历非递归解法，没有看懂，通过求根节点到两个所要找的节点的路径，使用栈存放，求出两个路径.
// 再求栈，从上到下找，的第一个相同的元素.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||p==nullptr||q==nullptr)
            return root;
        stack<TreeNode *> vp;
        stack<TreeNode *> vq;
        getpath(root,p,vp  );
        getpath(root,q,vq );
        TreeNode *lca = nullptr;  
    //找两个栈从栈顶向下找，第一个相同的元素。
         while(vp.size()!=vq.size())//先走差距步
         {
             if(vp.size()>vq.size())
             {
                 vp.pop();
             }
             else
             {
                 vq.pop();
             }
         }
        while(vp.top() !=vq.top() )
        {
            vp.pop();
            vq.pop();
        } 
        return vq.top();
    }
//求根节点到某一个节点的路径 存放在vt中 
    bool getpath(TreeNode* root,TreeNode* t,stack<TreeNode *> &vt  ){
        if(root==nullptr )
            return false;
        vt.push(root);
        bool found = false;
        if(root == t){
           found = true;
        }
        
        if(!found && root->left){
            found =  getpath(root->left,t,vt);
        }
         if(!found && root->right){
           found = getpath(root->right,t,vt);
        } 
        if(found)//注意，这里一定要返回，否则会删除前面压入的结点。
            return found;
        vt.pop(); 
        return fo
