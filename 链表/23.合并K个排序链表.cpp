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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // 题目：合并 k 个排序链表，返回合并后的排序链表。请
        // 思路：两两合并了链表，合并k-1次 
        // 时间复杂度：O(KN),k为链表的数目
        // 空间复杂度：O(1)
       
        if(lists.empty())
            return NULL;
        int n = lists.size();
        while(n > 1)
        {
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
        //合并两个链表的函数 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
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
