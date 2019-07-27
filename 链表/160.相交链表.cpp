class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //题目：找到两个单链表相交的起始节点。
        //因为链表是单向的，两个链表，只要相交就不会再分开
        //使用pA向后逐节点遍历A,pB逐节点向后遍历B,当pA到达A的尾部，将其重定位到B的头结点。当pB到达B的尾部的时候，将其重定位到A的头结点。
        //时间复杂度：O(M+N)
        //空间复杂度：O(1)
        
        if (headA==nullptr||headB==nullptr)
            return nullptr;
        ListNode *p1 = headA, *p2=headB;
        while (p1!=p2){
            p1 = (p1==nullptr)?headB:p1->next;  
            p2 = (p2==nullptr)?headA: p2->next; 
        }
        return p1;
    }
