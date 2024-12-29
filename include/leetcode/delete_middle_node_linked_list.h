
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* slow0 = head;
        ListNode* fast = head;

        if(!head){
            return head;
        }
        if(!head->next){
            return nullptr;
        }

        while(fast && fast->next){
            slow0=slow;
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }
        slow0->next = slow->next;
        delete slow;

        return head;
    }
};