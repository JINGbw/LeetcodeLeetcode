class Solution {
public:
    bool hasCycle(ListNode *head) {
        //给定一个链表，判断链表中是否有环
        //思路：1. 链表为空或者链表只有一个节点，那么链表中一定没有环
        //2. 使用两个快慢指针，如果两个指针相遇，则一定有环
        //时间复杂度 O(N)
        //空间复杂度 O(1) 因为只使用了两个快慢指针
        if (head==nullptr||head->next==nullptr)
            return false;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p1!=nullptr&&p2!=nullptr){
            if (p1==p2)
                return true;
            p1 = p1->next;
            p2 = p2->next;
            if (p2!=nullptr)
                p2 = p2->next;
        }
        return false;
    }
};
