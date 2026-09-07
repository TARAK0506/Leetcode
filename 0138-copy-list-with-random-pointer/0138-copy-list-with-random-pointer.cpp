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
    Node* insertCopyNodes(Node* head) {
        if (!head)
            return nullptr;
        Node* curr = head;
        while (curr) {
            Node* copyNode = new Node(curr->val);
            copyNode->next = curr->next;
            curr->next = copyNode;
            curr = copyNode->next;
        }
        return head;
    }
    Node* setRandomPointers(Node* head) {
        Node* curr = head;
        while (curr) {
            Node* copyNode = curr->next;
            copyNode->random = (!curr->random ? nullptr : curr->random->next);
            curr = copyNode->next;
        }
        return head;
    }
    Node* setNextPointers(Node* head) {
        Node* curr = head;
        if(!head || !head->next) return head;
        Node* copyHead = head->next;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            copy->next = (copy->next ? copy->next->next : nullptr);
            curr = curr->next;
        }
        return copyHead;
    }
    Node* copyRandomList(Node* head) {
        insertCopyNodes(head);
        setRandomPointers(head);
        return setNextPointers(head);
    }
};