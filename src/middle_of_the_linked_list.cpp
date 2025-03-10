#include "middle_of_the_linked_list.h"

ListNode* Solution::middleNode(ListNode* head) {
    // Use fast slow pointer
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
