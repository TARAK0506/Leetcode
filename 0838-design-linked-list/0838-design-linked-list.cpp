class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
private:
    Node* head;

public:
    MyLinkedList() : head(nullptr) {}

    int get(int index) {
        Node* curr = head;
        int count = 0;
        
        while (curr != nullptr) {
            if (count == index) {
                return curr->val;
            }
            curr = curr->next;
            count++;
        }
        return -1; 
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    
    void addAtIndex(int index, int val) {
        if (index < 0) return;  
        
        Node* newNode = new Node(val);
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* curr = head;
        int count = 0;
        while (curr != nullptr && count < index - 1) {
            curr = curr->next;
            count++;
        }
        
        if (curr == nullptr) return;  
        
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr) return;  
        
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        int count = 0;
        while (curr->next != nullptr && count < index - 1) {
            curr = curr->next;
            count++;
        }

        if (curr->next == nullptr) return;  
        
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    int listLength() {
        int length = 0;
        Node* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        return length;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
