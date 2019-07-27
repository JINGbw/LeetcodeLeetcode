/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //题目：对链表排序,时间复杂度要求O(NlogN),空间O(1) (数组归并排序空间复杂度为o(N))
        //思路：时间空间复杂度提示：二分法，归并排序
        // 1. 从中间断开
        // 2. Merge 
         
        if (head ==nullptr||head->next ==nullptr)
            return head;
    //1.找到当前链表中点，并从中点将链表断开
        ListNode *slow = head,*fast = head->next;
        while (fast &&fast->next){
     //2.使用 fast,slow 快慢双指针法，奇数个节点找到中点，偶数个节点找到中心左边的节点。
            fast = fast->next->next;
            slow = slow->next;//slow是重点 
         }
    //3. 断开中点    
        ListNode *mid = slow->next;
        slow->next = nullptr;
     // 4. 递归分割
        ListNode *left = sortList(head);//链表左端点 head
        ListNode * right = sortList(mid);// 中心节点 slow 的下一个节点 tmp
        
      return merge(left,right); 
    }
    ListNode*merge(ListNode* left,ListNode* right ){
        if (left ==nullptr)
            return right;
        if (right == nullptr)
            return left;
        if (left->val<right->val){
               left->next = merge(left->next,right); 
            return left;
           }
        else {
               right->next = merge(left,right->next); 
                return right;
           } 
        return nullptr;
    }
};
