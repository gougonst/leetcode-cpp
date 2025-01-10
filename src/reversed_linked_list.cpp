#include "reversed_linked_list.h"

ListNode* Solution::reverseListRecursive(ListNode* head) {
    return _reverseListRecursive(nullptr, head);
}

ListNode* Solution::_reverseListRecursive(ListNode* prev, ListNode* cur) {
    if (cur == nullptr) {
        return prev;
    }
    ListNode* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
    return _reverseListRecursive(prev, cur);
}

ListNode* Solution::reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
