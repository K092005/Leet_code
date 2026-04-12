class Solution {
public:


    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge2LL(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left) temp->next = left;
        else temp->next = right;

        return dummy->next;
    }

    
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = findMiddle(head);
        ListNode* right = mergeSort(mid->next);
        mid->next = nullptr;
        ListNode* left = mergeSort(head);

        return merge2LL(left, right);
    }


    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};