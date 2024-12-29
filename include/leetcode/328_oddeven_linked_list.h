struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head){ return nullptr;}
        ListNode* even = head;
        if(!(even->next)){return even;}
        ListNode* odd = head->next;
        ListNode* oddStart = odd;
        ListNode* run = odd->next;
        while(run){
            even->next = run;
            even = even->next;
            run = run->next;
            if(run){
                odd->next = run;
                odd = odd->next;
                run = run->next;
            } else{
                odd->next = nullptr;
            }
        }
        even->next = oddStart;
        return head;
    }
};