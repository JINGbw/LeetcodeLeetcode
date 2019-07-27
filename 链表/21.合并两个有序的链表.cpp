class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //题目：合并两个有序的链表 （双路归并）使用递归
        //思路：比较两个链表的第一个节点，再使用递归 
        //时间复杂度：O(N+M) 空间复杂度O(N+M)
        if(l1==nullptr)
            return l2;
        if (l2==nullptr)
            return l1;
         
        if (l1->val>l2->val){
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
        else{
            l1->next =  mergeTwoLists(l2,l1->next);
            return l1;
        }
        return nullptr ;
    }
};
