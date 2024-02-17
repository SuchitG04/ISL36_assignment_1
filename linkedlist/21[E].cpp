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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        
        ListNode *p = list1, *q = list2;
        ListNode *head, *cur;

        if (p == nullptr) {
            head = new ListNode(q->val);
            q = q->next;
        }
        else if (q == nullptr) {
            head = new ListNode(p->val);
            p = p->next;
        }
        else {
            if (p->val < q->val) {
                head = new ListNode(p->val);
                p = p->next;
            }
            else {
                head = new ListNode(q->val);
                q = q->next;
            }
        }
        cur = head;

        while (p != nullptr && q != nullptr) {
            if (p->val <= q->val) {
                cur->next = new ListNode(p->val);
                cur = cur->next;
                p = p->next;
            }
            else {
                cur->next = new ListNode(q->val);
                cur = cur->next;
                q = q->next;
            }
        }

        ListNode *temp = (p == nullptr) ? q : p;
        while (temp != nullptr) {
            cur->next = new ListNode(temp->val);
            cur = cur->next;
            temp = temp->next;
        }

        return head;
    }
};
