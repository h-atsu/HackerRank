/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <set>

bool has_cycle(Node* head) {
    set<Node *> seen;   //set of node pointer
    if (head == NULL) return false;
    while (head != NULL) {
        if (seen.find(head) != seen.end()) return true;
        seen.insert(head);
        head = head->next; // arrow operator  almost same as . attribute access
    }
    return false;
}
