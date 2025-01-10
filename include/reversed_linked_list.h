#include "list_node.h"

class Solution {
public:
    ListNode* reverseListRecursive(ListNode* head);
    ListNode* reverseListIterative(ListNode* head);
private:
    ListNode* _reverseListRecursive(ListNode* prev, ListNode* cur);
};
