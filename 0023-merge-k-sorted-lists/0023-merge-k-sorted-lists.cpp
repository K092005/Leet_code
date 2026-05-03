class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Min heap
        priority_queue<
            ListNode*, 
            vector<ListNode*>, 
            function<bool(ListNode*, ListNode*)>
        > pq([](ListNode* a, ListNode* b) {
            return a->val > b->val;
        });

        // Push first node of each list
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = curr;

            if (curr->next) {
                pq.push(curr->next);
            }
        }

        return dummy.next;
    }
};