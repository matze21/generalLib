/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>

using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToNew;

        Node* cur = head;
        while(cur){
            Node* newN = new Node(cur->val);
            oldToNew[cur] = newN;

            cur = cur->next;
        }
        cur = head;
        while(cur){
            oldToNew[cur]->next = oldToNew[cur->next];
            oldToNew[cur]->random = oldToNew[cur->random];
            cur = cur->next;
        }
        return oldToNew[head];
    }
};