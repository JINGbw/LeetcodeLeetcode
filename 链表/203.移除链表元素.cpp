class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //题目: 删除链表中值等于给定值的所有节点 
        //思路：1.创建一个虚拟头节点 （用一个指针记录）
        //2. 用另一个指针向后遍历 （如果该指针后面一个元素的值等于目标值） 删除
        //时间复杂度:O(N)
        //空间复杂度：O(1)
        ListNode *p1 = new ListNode(-1);
        p1->next = head;
        ListNode *p2 = p1;
        //确保当前节点 后面还有一个节点 
        while (p2->next!=nullptr){
            if (p2->next->val ==val){
                p2->next = p2->next->next;
            }
            else {
                p2 = p2->next;
            } 
        }
        return p1->next;
    }
