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
      struct comp
{
    bool operator()(const ListNode *lhs, const ListNode *rhs) const {
        return lhs->val > rhs->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue < ListNode*, vector<ListNode*>, comp > pq;
        
        for(ListNode* list : lists)
            if(list)
                pq.push(list);
        
        ListNode* head = nullptr, *tail = nullptr;
        
        while(!pq.empty())
        {
            ListNode* min  = pq.top();
            pq.pop();
            
            if(head == nullptr)
                head = tail = min;
            else{
                tail -> next = min;
                tail = min;
                
            }
            
            if(min -> next != nullptr)
                pq.push(min -> next);
        }
        
        return head;
    }
};