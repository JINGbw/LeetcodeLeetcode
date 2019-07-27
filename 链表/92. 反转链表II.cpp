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
        for(int j = m;j<n;j++){
            ListNode *nt = cur->next;
            cur->next = nt->next;
            nt->next = pre->next;
            pre->next = nt;
        }
          return dummy->next ; 
    } 
};
