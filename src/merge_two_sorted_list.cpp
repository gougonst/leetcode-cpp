#include "merge_two_sorted_list.h"

ListNode* Solution::mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    } else if (list2 == nullptr) {
        return list1;
    }

    ListNode* curPosition = new ListNode(-1);
    ListNode* dummyMergedList = curPosition;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            curPosition->next = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            curPosition->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        curPosition = curPosition->next;
    }

    if (list1) {
        curPosition->next = list1;
    } else {
        curPosition->next = list2;
    }

    ListNode* mergedList = dummyMergedList->next;
    delete dummyMergedList;

    return mergedList;
}

ListNode* Solution::mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    } else if (list2 == nullptr) {
        return list1;
    }

    if (list1->val < list2->val) {
        list1->next = mergeTwoListsRecursive(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoListsRecursive(list1, list2->next);
        return list2;
    }
}

