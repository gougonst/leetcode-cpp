#include <unordered_set>
#include "linked_list_cycle.h"
using namespace std;

bool Solution::hasCycleBySet(ListNode *head) {
    if (head == nullptr) {
        return false;
    }

    unordered_set<ListNode*> ancients{head};
    ListNode* current = head->next;
    while (current) {
        if (ancients.count(current)) {
            return true;
        } else {
            ancients.insert(current);
        }
        current = current->next;
    }
    return false;
}

bool Solution::hasCycleByTwoPointer(ListNode *head) {
    ListNode* hare = head;
    ListNode* turtle = head;
    while (hare != nullptr && hare->next != nullptr) {
        turtle = turtle->next;
        hare = hare->next->next;
        if (turtle == hare) {
            return true;
        }
    }
    return false;
}
