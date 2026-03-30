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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> um; 
        Node* curr = head;
        while (curr != nullptr) {
            Node* new_curr = new Node(curr->val);
            um[curr] = new_curr;
            curr = curr->next; 
        }
        curr = head; 
        while (curr != nullptr) {
            Node* temp = um[curr];
            temp->next = um[curr->next];
            temp->random = um[curr->random];
            curr = curr->next;
        }
        return um[head];
    }
};
