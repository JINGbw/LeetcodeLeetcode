class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //反转链表中的部分节点，使用一趟扫描完成反转
        //思路：使用三个指针pre,cur,nt 反转链表 
        //时间复杂度：O(N)
        //空间复杂度：O(1)
        if (head == nullptr && m>0)
            return nullptr;
        if (n<m)
            return nullptr;   
        ListNode * dummy = new ListNode (-1);
        dummy->next = head; 
        ListNode * pre = dummy ;
        for (int i = 0;i<m-1;i++){
            pre=pre->next; 
        }
        //pre指向第m-1个节点
        ListNode *cur = pre->next;
        //把t节点插到 cur和pre中间 
        for(int j = m;j<n;j++){
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
          return dummy->next ; 
    } 
};
