#include <iostream>
#include "list_node.h"
using namespace std;

void printList(ListNode* list) {
    if (list == nullptr) {
        return;
    }

    while (list) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

bool isListNodeEqual(ListNode* lhs, ListNode* rhs) {
    while (lhs != nullptr && rhs != nullptr) {
        if (lhs->val != rhs->val) {
            return false;
        }
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return lhs == rhs;
}
