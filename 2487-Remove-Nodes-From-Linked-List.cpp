/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode *head)
    {
        ListNode* tmp = head, *pre = nullptr;
        while ( tmp )
        {
            ListNode *front = tmp->next;
            tmp->next = pre;
            pre = tmp;
            tmp = front;
        }
        return head = pre;
    }
    ListNode* removeNodes(ListNode* head) 
    {
        head = reverse(head);
        ListNode *cur = head, *pre = head;
        int mock = 0;
        while ( cur )
        {
            if ( cur->val >= mock )
            {
                mock = cur->val;
                pre = cur;
            }
            else
            {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        head = reverse(head);
        return head;
    }
};