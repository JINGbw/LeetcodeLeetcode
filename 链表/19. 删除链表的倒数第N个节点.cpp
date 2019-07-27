class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //删除倒数第N个节点 
        //思路：两个指针间隔n个节点一直走到链表的尾部
        //时间复杂度O(N)
        //空间复杂度O(1)
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p1 = dummy;
        ListNode *p2 = dummy;
        //一个指针向前走n步 
        for(int i = 0;i<n+1;i++){
            p1 = p1->next;
        }
        //两个指针一起向前走
        while (p1!=nullptr){
            p1 = p1->next;
            p2 =p2->next;
        }
        //删除倒数第n个节点
        p2->next = p2->next->next;
        return dummy->next;
    }
};
