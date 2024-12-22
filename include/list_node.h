#ifndef LIST_NODE_H
#define LIST_NODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* list);
bool isListNodeEqual(ListNode* lhs, ListNode* rhs);

#endif
